package pkglint

import (
	"context"
	"errors"
	"gopkg.in/check.v1"
	"net"
	"net/http"
	"strconv"
	"syscall"
	"time"
)

func (s *Suite) Test_NewHomepageChecker(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"HOMEPAGE=\t# none")
	mkline := mklines.mklines[0]

	ck := NewHomepageChecker("value", "valueNoVar", mkline, mklines)

	t.CheckEquals(ck.Value, "value")
	t.CheckEquals(ck.ValueNoVar, "valueNoVar")
}

func (s *Suite) Test_HomepageChecker_Check(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"HOMEPAGE=\tftp://example.org/")
	mkline := mklines.mklines[0]
	value := mkline.Value()

	ck := NewHomepageChecker(value, value, mkline, mklines)

	ck.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:1: An FTP URL does not represent a user-friendly homepage.")
}

func (s *Suite) Test_HomepageChecker_checkBasedOnMasterSites(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtHomepage)

	vt.Varname("HOMEPAGE")
	vt.Values(
		"${MASTER_SITES}")

	vt.Output(
		"WARN: filename.mk:1: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	pkg := NewPackage(t.File("category/package"))
	vt.Package(pkg)

	vt.Values(
		"${MASTER_SITES}")

	// When this assignment occurs while checking a package, but the package
	// doesn't define MASTER_SITES, that variable cannot be expanded, which means
	// the warning cannot suggest a replacement value.
	vt.Output(
		"WARN: filename.mk:11: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	delete(pkg.vars.firstDef, "MASTER_SITES")
	delete(pkg.vars.lastDef, "MASTER_SITES")
	pkg.vars.Define("MASTER_SITES", t.NewMkLine(pkg.File("Makefile"), 5,
		"MASTER_SITES=\thttps://cdn.NetBSD.org/pub/pkgsrc/distfiles/"))

	vt.Values(
		"${MASTER_SITES}")

	vt.Output(
		"WARN: filename.mk:21: HOMEPAGE should not be defined in terms of MASTER_SITEs. " +
			"Use https://cdn.NetBSD.org/pub/pkgsrc/distfiles/ directly.")

	delete(pkg.vars.firstDef, "MASTER_SITES")
	delete(pkg.vars.lastDef, "MASTER_SITES")
	pkg.vars.Define("MASTER_SITES", t.NewMkLine(pkg.File("Makefile"), 5,
		"MASTER_SITES=\t${MASTER_SITE_GITHUB}"))

	vt.Values(
		"${MASTER_SITES}")

	// When MASTER_SITES itself makes use of another variable, pkglint doesn't
	// resolve that variable and just outputs the simple variant of this warning.
	vt.Output(
		"WARN: filename.mk:31: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	delete(pkg.vars.firstDef, "MASTER_SITES")
	delete(pkg.vars.lastDef, "MASTER_SITES")
	pkg.vars.Define("MASTER_SITES", t.NewMkLine(pkg.File("Makefile"), 5,
		"MASTER_SITES=\t# none"))

	vt.Values(
		"${MASTER_SITES}")

	// When MASTER_SITES is empty, pkglint cannot extract the first of the URLs
	// for using it in the HOMEPAGE.
	vt.Output(
		"WARN: filename.mk:41: HOMEPAGE should not be defined in terms of MASTER_SITEs.")
}

func (s *Suite) Test_HomepageChecker_checkFtp(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtHomepage)

	vt.Varname("HOMEPAGE")
	vt.Values(
		"ftp://example.org/",
		"ftp://example.org/ # no HTTP homepage available")

	vt.Output(
		"WARN: filename.mk:1: " +
			"An FTP URL does not represent a user-friendly homepage.")
}

func (s *Suite) Test_HomepageChecker_checkHttp(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtHomepage)

	vt.Varname("HOMEPAGE")
	vt.Values(
		"http://www.gnustep.org/",
		"http://www.pkgsrc.org/",
		"http://project.sourceforge.net/",
		"http://sf.net/p/project/",
		"http://sourceforge.net/p/project/",
		"http://example.org/ # doesn't support https",
		"http://example.org/ # only supports http",
		"http://asf.net/")

	vt.Output(
		"WARN: filename.mk:4: HOMEPAGE should migrate " +
			"from http://sf.net to https://sourceforge.net.")

	t.SetUpCommandLine("--autofix")
	vt.Values(
		"http://www.gnustep.org/",
		"http://www.pkgsrc.org/",
		"http://project.sourceforge.net/",
		"http://sf.net/p/project/",
		"http://sourceforge.net/p/project/",
		"http://example.org/ # doesn't support https",
		"http://example.org/ # only supports http",
		"http://kde.org/",
		"http://asf.net/")

	// www.gnustep.org does not support https at all.
	// www.pkgsrc.org is not in the (short) list of known https domains,
	// therefore pkglint does not dare to change it automatically.
	vt.Output(
		"AUTOFIX: filename.mk:14: Replacing \"http://sf.net\" "+
			"with \"https://sourceforge.net\".",
		"AUTOFIX: filename.mk:18: Replacing \"http\" with \"https\".")
}

func (s *Suite) Test_HomepageChecker_migrate(c *check.C) {
	t := s.Init(c)

	reachable := map[string]YesNoUnknown{}
	used := map[string]bool{}

	isReachable := func(url string) YesNoUnknown {
		if r, ok := reachable[url]; ok {
			used[url] = true
			return r
		}
		panic(url)
	}

	test := func(url string, migrate bool, from, to string) {
		ck := NewHomepageChecker(url, url, nil, nil)
		ck.isReachable = isReachable

		actualMigrate, actualFrom, actualTo := ck.migrate(url)

		t.CheckDeepEquals(
			[]interface{}{actualMigrate, actualFrom, actualTo},
			[]interface{}{migrate, from, to})

		for key, _ := range reachable {
			assertf(used[key], "Reachability of %q was not used.", key)
			delete(reachable, key)
		}
	}

	reachable["https://localhost/"] = unknown
	test(
		"http://localhost/",
		false,
		"",
		"")

	reachable["https://localhost/"] = yes
	test(
		"http://localhost/",
		true,
		"http",
		"https")

	reachable["https://project.sourceforge.io/"] = unknown
	test(
		"http://project.sourceforge.net/",
		false,
		"",
		"")

	reachable["https://project.sourceforge.io/"] = yes
	test(
		"http://project.sourceforge.net/",
		true,
		"http://project.sourceforge.net",
		"https://project.sourceforge.io")

	// To clean up the wrong autofix from 2020-01-18:
	// https://mail-index.netbsd.org/pkgsrc-changes/2020/01/18/msg205146.html
	reachable["https://project.sourceforge.io/"] = yes
	test(
		"https://project.sourceforge.net/",
		true,
		"sourceforge.net",
		"sourceforge.io")

	// To clean up the wrong autofix from 2020-01-18:
	// https://mail-index.netbsd.org/pkgsrc-changes/2020/01/18/msg205146.html
	//
	// If neither of the https URLs is reachable, the homepage
	// is rolled back to the http URL.
	reachable["https://project.sourceforge.io/"] = no
	reachable["http://project.sourceforge.net/"] = yes
	reachable["https://project.sourceforge.net/"] = no
	test(
		"https://project.sourceforge.net/",
		true,
		"https",
		"http")

	// To clean up the wrong autofix from 2020-01-18:
	// https://mail-index.netbsd.org/pkgsrc-changes/2020/01/18/msg205146.html
	//
	// If the https URL of sourceforge.net is reachable,
	// it is preferred over the http URL,
	// even though it is not mentioned in the SourceForge documentation.
	reachable["https://project.sourceforge.io/"] = no
	reachable["http://project.sourceforge.net/"] = yes
	reachable["https://project.sourceforge.net/"] = yes
	test(
		"https://project.sourceforge.net/",
		false,
		"",
		"")

	// To clean up the wrong autofix from 2020-01-18:
	// https://mail-index.netbsd.org/pkgsrc-changes/2020/01/18/msg205146.html
	reachable["https://project.sourceforge.io/"] = no
	reachable["http://project.sourceforge.net/"] = no
	test(
		"https://project.sourceforge.net/",
		false,
		"",
		"")

	// Since the URL contains a variable, it cannot be resolved.
	// Therefore it is skipped without any HTTP request being sent.
	test(
		"http://godoc.org/${GO_SRCPATH}",
		false,
		"",
		"")
}

func (s *Suite) Test_HomepageChecker_checkBadUrls(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtHomepage)

	vt.Varname("HOMEPAGE")
	vt.Values(
		"http://garr.dl.sourceforge.net/project/name/dir/subdir/",
		"https://downloads.sourceforge.net/project/name/dir/subdir/")

	vt.Output(
		"WARN: filename.mk:1: A direct download URL is not a user-friendly homepage.",
		"WARN: filename.mk:2: A direct download URL is not a user-friendly homepage.")
}

func (s *Suite) Test_HomepageChecker_checkReachable(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtHomepage)

	t.SetUpCommandLine("--network")

	mux := http.NewServeMux()
	mux.HandleFunc("/status/", func(writer http.ResponseWriter, request *http.Request) {
		location := request.URL.Query().Get("location")
		if location != "" {
			writer.Header().Set("Location", location)
		}

		status, err := strconv.Atoi(request.URL.Path[len("/status/"):])
		assertNil(err, "")
		writer.WriteHeader(status)
	})
	mux.HandleFunc("/timeout", func(http.ResponseWriter, *http.Request) {
		time.Sleep(5 * time.Second)
	})

	// 28780 = 256 * 'p' + 'l'
	srv := http.Server{Addr: "localhost:28780", Handler: mux}
	listener, err := net.Listen("tcp", srv.Addr)
	assertNil(err, "")
	shutdown := make(chan bool)

	go func() {
		err = srv.Serve(listener)
		assertf(err == http.ErrServerClosed, "%s", err)
		shutdown <- true
	}()

	defer func() {
		err := srv.Shutdown(context.Background())
		assertNil(err, "")
		<-shutdown
	}()

	vt.Varname("HOMEPAGE")
	vt.Values(
		"http://localhost:28780/status/200",
		"http://localhost:28780/status/301?location=/redirect301",
		"http://localhost:28780/status/302?location=/redirect302",
		"http://localhost:28780/status/307?location=/redirect307",
		"http://localhost:28780/status/404",
		"http://localhost:28780/status/500")

	vt.Output(
		"WARN: filename.mk:2: Homepage "+
			"\"http://localhost:28780/status/301?location=/redirect301\" "+
			"redirects to \"http://localhost:28780/redirect301\".",
		"WARN: filename.mk:3: Homepage "+
			"\"http://localhost:28780/status/302?location=/redirect302\" "+
			"redirects to \"http://localhost:28780/redirect302\".",
		"WARN: filename.mk:4: Homepage "+
			"\"http://localhost:28780/status/307?location=/redirect307\" "+
			"redirects to \"http://localhost:28780/redirect307\".",
		"WARN: filename.mk:5: Homepage \"http://localhost:28780/status/404\" "+
			"returns HTTP status \"404 Not Found\".",
		"WARN: filename.mk:6: Homepage \"http://localhost:28780/status/500\" "+
			"returns HTTP status \"500 Internal Server Error\".")

	vt.Values(
		"http://localhost:28780/timeout")

	vt.Output(
		"WARN: filename.mk:11: Homepage \"http://localhost:28780/timeout\" " +
			"cannot be checked: timeout")

	vt.Values(
		"http://localhost:28780/%invalid")

	vt.Output(
		"ERROR: filename.mk:21: Invalid URL \"http://localhost:28780/%invalid\".")

	vt.Values(
		"http://localhost:28781/")

	// The "unknown network error" is for compatibility with Go < 1.13.
	t.CheckOutputMatches(
		`^WARN: filename\.mk:31: Homepage "http://localhost:28781/" ` +
			`cannot be checked: (connection refused|unknown network error:.*)$`)

	vt.Values(
		"https://no-such-name.example.org/")

	// The "unknown network error" is for compatibility with Go < 1.13.
	t.CheckOutputMatches(
		`^WARN: filename\.mk:41: Homepage "https://no-such-name.example.org/" ` +
			`cannot be checked: (name not found|unknown network error:.*)$`)

	vt.Values(
		"https://!!!invalid/")

	t.CheckOutputLines(
		"WARN: filename.mk:51: \"https://!!!invalid/\" is not a valid URL.")
}

func (s *Suite) Test_HomepageChecker_isReachableOnline(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--network")

	mux := http.NewServeMux()
	mux.HandleFunc("/status/", func(writer http.ResponseWriter, request *http.Request) {
		location := request.URL.Query().Get("location")
		if location != "" {
			writer.Header().Set("Location", location)
		}

		status, err := strconv.Atoi(request.URL.Path[len("/status/"):])
		assertNil(err, "")
		writer.WriteHeader(status)
	})
	mux.HandleFunc("/timeout", func(http.ResponseWriter, *http.Request) {
		time.Sleep(5 * time.Second)
	})
	mux.HandleFunc("/ok/", func(http.ResponseWriter, *http.Request) {})

	// 28780 = 256 * 'p' + 'l'
	srv := http.Server{Addr: "localhost:28780", Handler: mux}
	listener, err := net.Listen("tcp", srv.Addr)
	assertNil(err, "")
	shutdown := make(chan bool)

	go func() {
		err := srv.Serve(listener)
		assertf(err == http.ErrServerClosed, "%s", err)
		shutdown <- true
	}()

	defer func() {
		err := srv.Shutdown(context.Background())
		assertNil(err, "")
		<-shutdown
	}()

	test := func(url string, reachable YesNoUnknown) {
		ck := NewHomepageChecker(url, url, nil, nil)
		actual := ck.isReachableOnline(url)

		t.CheckEquals(actual, reachable)
	}

	test("http://localhost:28780/status/200", yes)
	test("http://localhost:28780/status/301?location=/", no)
	test("http://localhost:28780/status/404", no)
	test("http://localhost:28780/status/500", no)
	test("http://localhost:28780/timeout", no)
	test("http://localhost:28780/ok/${VAR}", unknown)
	test("http://localhost:28780/ invalid", unknown)
	test("http://localhost:28780/%invalid", no)
	test("http://localhost:28781/", no)
}

func (s *Suite) Test_HomepageChecker_hasAnySuffix(c *check.C) {
	t := s.Init(c)

	test := func(s string, hasAnySuffix bool, suffixes ...string) {
		actual := (*HomepageChecker).hasAnySuffix(nil, s, suffixes...)

		t.CheckEquals(actual, hasAnySuffix)
	}

	test("example.org", true, "org")
	test("example.com", false, "org")
	test("example.org", true, "example.org")
	test("example.org", false, ".example.org")
	test("example.org", true, ".org")
}

func (s *Suite) Test_HomepageChecker_classifyNetworkError(c *check.C) {
	t := s.Init(c)

	test := func(err error, expectedClass string) {
		actual := (*HomepageChecker).classifyNetworkError(nil, err)

		t.CheckEquals(actual, expectedClass)
	}

	test(syscall.Errno(10061), "connection refused")
	test(syscall.ECONNREFUSED, "connection refused")
	test(errors.New("unknown"), "unknown network error: unknown")
}
