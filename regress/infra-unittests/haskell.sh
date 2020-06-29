#! /bin/sh
# $NetBSD: haskell.sh,v 1.2 2020/06/29 20:12:34 rillig Exp $
#
# Tests for mk/haskell.mk.
#

set -eu

. './test.subr'

link_from_pkgsrc() {
	for f in "$@"; do
		mkdir -p "$mocked_pkgsrcdir/$(dirname "$f")"
		rm -f "$mocked_pkgsrcdir/$f"
		ln -s "$pkgsrcdir/$f" "$mocked_pkgsrcdir/$f"
	done
}

test_case_set_up() {

	destdir="$PWD/destdir"
	prefix="$PWD/prefix"
	pkgdir="$mocked_pkgsrcdir/category/package"

	mock_ghc=$(mock_cmd ghc \
		--when-args '-V' --then-output 'The Glorious Glasgow Haskell Compilation System, version 8.8.1'
	)

	mkdir -p "$prefix/bin"
	mv "$mock_ghc" "$prefix/bin/"

	rm -rf "$mocked_pkgsrcdir"
	mkdir -p "$pkgdir"
	cd "$mocked_pkgsrcdir"

	create_file 'mk/bsd.fast.prefs.mk' <<-EOF
		OPSYS=			Opsys
		HASKELL_COMPILER=	ghc
		SHLIB_TYPE=		ELF

		AWK=			awk
		CAT=			cat
		CUT=			cut
		ECHO=			echo
		FIND=			find
		GREP=			grep
		MKDIR=			mkdir -p
		PKGSRC_SETENV=		env
		SORT=			sort
		TRUE=			true
	EOF
	create_file 'lang/ghc88/buildlink3.mk' <<-EOF
		# Nothing essential
	EOF
	create_file 'main.mk' <<EOF
.include "mk/bsd.fast.prefs.mk"

# override for platform-independent test results
MACHINE_ARCH=		arch

PKGDIR=			\${.:L:tA}
WRKDIR=			$PWD/work
PLIST=			\${WRKDIR}/.PLIST
PREFIX=			$prefix
DESTDIR=		$destdir
PKGSRCDIR=		$pkgsrcdir
RUN=			@set -eu;
ALL_ENV=		ALL_ENV_VAR=value

.include "mk/haskell.mk"
.include "mk/plist/bsd.plist.mk"
.include "mk/misc/show.mk"

show-plist-status: .PHONY
	@echo "PLIST status: "\${_HS_PLIST_STATUS:Q}
EOF

	link_from_pkgsrc 'mk/haskell.mk'
	link_from_pkgsrc 'mk/plist'
	link_from_pkgsrc 'mk/misc'

	cd "$pkgdir"
}


if test_case_begin 'PLIST status: missing'; then

	create_file 'Makefile' <<-EOF
		DISTNAME=	package-1.0

		.include "../../main.mk"
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: missing'

	test_case_end
fi


if test_case_begin 'PLIST status: missing for empty file'; then

	create_file 'Makefile' <<-EOF
		DISTNAME=	package-1.0

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-EOF
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: missing'

	test_case_end
fi


if test_case_begin 'PLIST status: plain'; then

	# See textproc/hs-cgrep/PLIST, r1.4.

	create_file 'Makefile' <<-EOF
		DISTNAME=	cgrep-6.6.30

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-EOF
		bin/cgrep
		share/doc/x86_64-ghc-8.8.1/cgrep-\${PKGVERSION}/LICENSE
		@pkgdir lib/cgrep-\${PKGVERSION}/ghc-8.8.1
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: plain'

	test_case_end
fi


if test_case_begin 'PLIST status: outdated'; then

	# See devel/hs-hashable/PLIST, r1.1.

	create_file 'Makefile' <<-EOF
		DISTNAME=	hashable-1.3.0.0

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-EOF
		lib/hashable-\${PKGVERSION}/\${HASKELL_VERSION}/Data/Hashable.hi
		lib/hashable-\${PKGVERSION}/\${HASKELL_VERSION}/package-description
		share/doc/hashable-\${PKGVERSION}/LICENSE
		\${PLIST.doc}share/doc/hashable-\${PKGVERSION}/html/Data-Hashable.html
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	# TODO: should be 'outdated' because of 'package-description'
	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: plain'

	test_case_end
fi


if test_case_begin 'PLIST status: lib-ok'; then

	# See devel/hs-hashable/PLIST, r1.3.

	create_file 'Makefile' <<-EOF
		DISTNAME=	hashable-1.3.0.0

		.include "../../main.mk"
	EOF
	create_file 'PLIST' <<-'EOF'
		${HS_INTF}/package-description
		${HS_INTF}/package-id
		${HS_IMPL}/Data/Hashable.dyn_hi
		lib/${HS_PLATFORM}/libHS${HS_PKGID}-${HS_VER}.so
		${HS_DOCS}/LICENSE
	EOF

	"$make" 'show-plist-status' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'PLIST status: lib-ok'

	test_case_end
fi


if test_case_begin 'missing, update=yes'; then

	# Based on devel/hs-asn1-parse from 2020-06-22.

	create_file_lines 'Makefile' \
		'DISTNAME=	asn1-parse-0.9.5' \
		'PKGVERSION=	0.9.5' \
		'PKGNAME_NOREV=	${DISTNAME}' \
		'' \
		'HS_UPDATE_PLIST=	yes' \
		"PKGDIR=	$PWD" \
		'' \
		'.include "../../main.mk"' \
		'.include "../../mk/haskell.mk"' \
		'' \
		'show-haskell-plist-status: .PHONY' \
		'	@echo "PLIST status: "${_HS_PLIST_STATUS:Q}'
	create_file "$destdir$prefix/lib/asn1-parse-0.9.5/ghc-8.8.1/package-id" <<-EOF
		asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr
	EOF
	create_file "$destdir$prefix/lib/asn1-parse-0.9.5/ghc-8.8.1/package-description" <<-EOF
		...
		import-dirs:
		    $prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr

		...
	EOF
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/Data/ASN1/Parse.dyn_hi" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/Data/ASN1/Parse.hi" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/Data/ASN1/Parse.p_hi" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/libHSasn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr.a" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/libHSasn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr_p.a" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/libHSasn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr-ghc8.8.1.so" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/asn1-parse.haddock" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/Data-ASN1-Parse.html" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/doc-index.html" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/haddock-bundle.min.js" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/index.html" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/linuwial.css" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/meta.json" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/quick-jump.css" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/synopsis.png" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/LICENSE" ''

	"$make" 'plist' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-empty

	assert_that "PLIST" --file-is-lines \
		'@comment $''NetBSD$' \
		'${HS_INTF}/package-description' \
		'${HS_INTF}/package-id' \
		'${HS_IMPL}/Data/ASN1/Parse.dyn_hi' \
		'${HS_IMPL}/Data/ASN1/Parse.hi' \
		'${HS_IMPL}/Data/ASN1/Parse.p_hi' \
		'${HS_IMPL}/libHS${HS_PKGID}.a' \
		'${HS_IMPL}/libHS${HS_PKGID}_p.a' \
		'lib/${HS_PLATFORM}/libHS${HS_PKGID}-${HS_VER}.so' \
		'${HS_DOCS}/LICENSE' \
		'${HS_DOCS}/html/Data-ASN1-Parse.html' \
		'${HS_DOCS}/html/asn1-parse.haddock' \
		'${HS_DOCS}/html/doc-index.html' \
		'${HS_DOCS}/html/haddock-bundle.min.js' \
		'${HS_DOCS}/html/index.html' \
		'${HS_DOCS}/html/linuwial.css' \
		'${HS_DOCS}/html/meta.json' \
		'${HS_DOCS}/html/quick-jump.css' \
		'${HS_DOCS}/html/synopsis.png'

	test_case_end
fi


if test_case_begin 'missing, update=no'; then

	# Based on devel/hs-asn1-parse from 2020-06-22.

	create_file_lines 'Makefile' \
		'DISTNAME=	asn1-parse-0.9.5' \
		'ECHO=		echo' \
		'ALL_ENV=	ENVVAR=envvalue' \
		'CAT=		cat' \
		'SORT=		sort' \
		'RUN=		@' \
		'FIND=		find' \
		'PKGVERSION=	0.9.5' \
		'PKGNAME_NOREV=	${DISTNAME}' \
		'' \
		'HS_UPDATE_PLIST=	no' \
		'' \
		'.include "../../main.mk"' \
		'.include "../../mk/haskell.mk"' \
		'.include "../../mk/plist/print-plist.mk"' \
		'' \
		'show-all: .PHONY' \
		'	@echo "PLIST status: "${_HS_PLIST_STATUS:Q}'
	create_file "$destdir$prefix/lib/asn1-parse-0.9.5/ghc-8.8.1/package-description" <<-EOF
		...
		import-dirs:
		    $prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr

		...
	EOF
	create_file_lines "$destdir$prefix/lib/asn1-parse-0.9.5/ghc-8.8.1/package-id" \
		'asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr'
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/Data/ASN1/Parse.dyn_hi" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/Data/ASN1/Parse.hi" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/Data/ASN1/Parse.p_hi" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/libHSasn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr.a" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr/libHSasn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr_p.a" ''
	create_file_lines "$destdir$prefix/lib/x86_64-netbsd-ghc-8.8.1/libHSasn1-parse-0.9.5-2HryHNyN1grJJzKM4AV1Gr-ghc8.8.1.so" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/asn1-parse.haddock" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/Data-ASN1-Parse.html" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/doc-index.html" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/haddock-bundle.min.js" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/index.html" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/linuwial.css" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/meta.json" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/quick-jump.css" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/html/synopsis.png" ''
	create_file_lines "$destdir$prefix/share/doc/x86_64-netbsd-ghc-8.8.1/asn1-parse-0.9.5/LICENSE" ''

	"$make" 'plist' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-empty

	"$make" 'print-PLIST' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'@comment $''NetBSD$' \
		'${HS_INTF}/package-description' \
		'${HS_INTF}/package-id' \
		'${HS_IMPL}/Data/ASN1/Parse.dyn_hi' \
		'${HS_IMPL}/Data/ASN1/Parse.hi' \
		'${HS_IMPL}/Data/ASN1/Parse.p_hi' \
		'${HS_IMPL}/libHS${HS_PKGID}.a' \
		'${HS_IMPL}/libHS${HS_PKGID}_p.a' \
		'lib/${HS_PLATFORM}/libHS${HS_PKGID}-${HS_VER}.so' \
		'${HS_DOCS}/LICENSE' \
		'${HS_DOCS}/html/Data-ASN1-Parse.html' \
		'${HS_DOCS}/html/asn1-parse.haddock' \
		'${HS_DOCS}/html/doc-index.html' \
		'${HS_DOCS}/html/haddock-bundle.min.js' \
		'${HS_DOCS}/html/index.html' \
		'${HS_DOCS}/html/linuwial.css' \
		'${HS_DOCS}/html/meta.json' \
		'${HS_DOCS}/html/quick-jump.css' \
		'${HS_DOCS}/html/synopsis.png'

	test_case_end
fi


if test_case_begin 'plain, update=yes'; then

	# TODO

	test_case_end
fi


if test_case_begin 'outdated, update=yes'; then

	# TODO

	test_case_end
fi


if test_case_begin 'lib-ok, update=yes'; then

	# TODO

	test_case_end
fi


if test_case_begin 'plain, update=no'; then

	# TODO

	test_case_end
fi


if test_case_begin 'outdated, update=no'; then

	# TODO

	test_case_end
fi


if test_case_begin 'lib-ok, update=no'; then

	# TODO

	test_case_end
fi


if test_case_begin 'neither package-id nor package-description'; then

	# example: textproc/hs-cgrep

	create_file_lines 'destdir/prefix/bin/cgrep' 'line'
	create_file_lines 'destdir/prefix/share/doc/x86_64-netbsd-ghc-8.8.1/cgrep-6.6.30/LICENSE' 'line'

	create_file_lines 'Makefile' \
		'DISTNAME=	package-1.0' \
		'' \
		".include \"../../main.mk\"" \
		'.include "../../mk/haskell.mk"' \
		'' \
		'show-haskell-plist: .PHONY' \
		'	@echo _HS_PLIST_STATUS=${_HS_PLIST_STATUS:Q}' \
		'	@printf "PLIST_SUBST %s\n" ${PLIST_SUBST}' \
		'	@printf "PRINT_PLIST_AWK %s\n" ${PRINT_PLIST_AWK:M*:@arg@${arg:Q}@}'

	"$make" 'show-haskell-plist' 1> "$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'_HS_PLIST_STATUS=missing' \
		"awk: can't open file $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-description" \
		' source line number 1' \
		'bmake: "awk '\''prev == "import-dirs:" { dir = $1; exit } { prev = $0 } END { print(dir ? dir : "never_match_this") }'\'' '"$destdir""$prefix"'/lib/package-1.0/ghc-8.8.1/package-description" returned non-zero status' \
		"awk: can't open file $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-description" \
		' source line number 1' \
		'bmake: "awk '\''prev == "import-dirs:" { dir = $1; exit } { prev = $0 } END { print(dir ? dir : "never_match_this") }'\'' '"$destdir""$prefix"'/lib/package-1.0/ghc-8.8.1/package-description" returned non-zero status' \
		"awk: can't open file $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-description" \
		' source line number 1' \
		'bmake: "awk '\''prev == "import-dirs:" { dir = $1; exit } { prev = $0 } END { print(dir ? dir : "never_match_this") }'\'' '"$destdir""$prefix"'/lib/package-1.0/ghc-8.8.1/package-description" returned non-zero status' \
		"cat: $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-id: No such file or directory" \
		"$make: \"cat $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-id\" returned non-zero status" \
		'PLIST_SUBST HS_INTF=lib/package-1.0/ghc-8.8.1' \
		'PLIST_SUBST HS_IMPL=' \
		'PLIST_SUBST HS_DOCS=' \
		'PLIST_SUBST HS_PLATFORM=never_match_this' \
		'PLIST_SUBST HS_PKGID=' \
		'PLIST_SUBST HS_VER=ghc8.8.1' \
		'PLIST_SUBST OPSYS=Opsys' \
		'PLIST_SUBST OS_VERSION=' \
		'PLIST_SUBST MACHINE_ARCH=arch' \
		'PLIST_SUBST MACHINE_GNU_ARCH=' \
		'PLIST_SUBST MACHINE_GNU_PLATFORM=' \
		'PLIST_SUBST LN=' \
		'PLIST_SUBST LOWER_VENDOR=' \
		'PLIST_SUBST LOWER_OPSYS=' \
		'PLIST_SUBST LOWER_OS_VERSION=' \
		'PLIST_SUBST PKGBASE=' \
		'PLIST_SUBST PKGNAME=' \
		'PLIST_SUBST PKGLOCALEDIR=' \
		'PLIST_SUBST PKGVERSION=' \
		'PLIST_SUBST LOCALBASE=' \
		'PLIST_SUBST VIEWBASE=' \
		'PLIST_SUBST X11BASE=' \
		'PLIST_SUBST CHGRP=' \
		'PLIST_SUBST CHMOD=' \
		'PLIST_SUBST CHOWN=' \
		'PLIST_SUBST MKDIR=mkdir -p' \
		'PLIST_SUBST RMDIR=' \
		'PLIST_SUBST RM=' \
		'PLIST_SUBST TRUE=true' \
		'PLIST_SUBST PKGGNUDIR=' \
		'PLIST_SUBST PKGMANDIR=' \
		"awk: can't open file $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-description" \
		' source line number 1' \
		'bmake: "awk '\''prev == "import-dirs:" { dir = $1; exit } { prev = $0 } END { print(dir ? dir : "never_match_this") }'\'' '"$destdir""$prefix"'/lib/package-1.0/ghc-8.8.1/package-description" returned non-zero status' \
		"awk: can't open file $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-description" \
		' source line number 1' \
		'bmake: "awk '\''prev == "import-dirs:" { dir = $1; exit } { prev = $0 } END { print(dir ? dir : "never_match_this") }'\'' '"$destdir""$prefix"'/lib/package-1.0/ghc-8.8.1/package-description" returned non-zero status' \
		"awk: can't open file $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-description" \
		' source line number 1' \
		'bmake: "awk '\''prev == "import-dirs:" { dir = $1; exit } { prev = $0 } END { print(dir ? dir : "never_match_this") }'\'' '"$destdir""$prefix"'/lib/package-1.0/ghc-8.8.1/package-description" returned non-zero status' \
		"cat: $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-id: No such file or directory" \
		"$make: \"cat $destdir$prefix/lib/package-1.0/ghc-8.8.1/package-id\" returned non-zero status" \
		'PRINT_PLIST_AWK {' \
		'PRINT_PLIST_AWK sub("^lib/package-1.0/ghc-8.8.1",' \
		'PRINT_PLIST_AWK "")' \
		'PRINT_PLIST_AWK }' \
		'PRINT_PLIST_AWK {' \
		'PRINT_PLIST_AWK sub("^",' \
		'PRINT_PLIST_AWK "")' \
		'PRINT_PLIST_AWK }' \
		'PRINT_PLIST_AWK {' \
		'PRINT_PLIST_AWK sub("^",' \
		'PRINT_PLIST_AWK "")' \
		'PRINT_PLIST_AWK }' \
		'PRINT_PLIST_AWK {' \
		'PRINT_PLIST_AWK sub("/never_match_this/",' \
		'PRINT_PLIST_AWK "//")' \
		'PRINT_PLIST_AWK }' \
		'PRINT_PLIST_AWK {' \
		'PRINT_PLIST_AWK sub(' \
		'PRINT_PLIST_AWK "",' \
		'PRINT_PLIST_AWK "")' \
		'PRINT_PLIST_AWK }' \
		'PRINT_PLIST_AWK {' \
		'PRINT_PLIST_AWK sub(' \
		'PRINT_PLIST_AWK "ghc8.8.1",' \
		'PRINT_PLIST_AWK "")' \
		'PRINT_PLIST_AWK }'

	test_case_end
fi


if test_case_begin 'package-description, but no library'; then

	# example: devel/hs-fail

	# TODO

	test_case_end
fi


if test_case_begin 'package-description + library'; then

	# example: security/hs-SHA

	# TODO

	test_case_end
fi
