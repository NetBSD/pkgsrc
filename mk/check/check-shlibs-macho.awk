# $NetBSD: check-shlibs-macho.awk,v 1.2 2016/02/19 15:10:23 jperkin Exp $

#
# Read a list of potential Mach-O binaries from stdin.
# For each, check the list of required DSOs and ensure that each of them can
# be found correctly, and check that any pkgsrc-installed DSOs belong to a
# full dependency.
#

function shquote(IN,	out) {
	out = IN;
	gsub("\\\\", "\\\\", out);
	gsub("\\\n", "\\n", out);
	gsub("\\\t", "\\t", out);
	gsub(" ", "\\ ", out);
	gsub("'", "\\'", out);
	gsub("`", "\\`", out);
	gsub("\"", "\\\"", out);
	gsub(";", "\\;", out);
	gsub("&", "\\&", out);
	gsub("<", "\\<", out);
	gsub(">", "\\>", out);
	gsub("\\(", "\\(", out);
	gsub("\\)", "\\)", out);
	gsub("\\|", "\\|", out);
	gsub("\\*", "\\*", out);
	gsub("\\?", "\\?", out);
	gsub("\\{", "\\{", out);
	gsub("\\}", "\\}", out);
	gsub("\\[", "\\[", out);
	gsub("\\]", "\\]", out);
	gsub("\\$", "\\$", out);
	gsub("!", "\\!", out);
	gsub("#", "\\#", out);
	gsub("\\^", "\\^", out);
	gsub("~", "\\~", out);
	return out;
}

function check_pkg(DSO, 	pkg, found) {
	if (destdir == "")
		return 0
	if (DSO in pkgcache) {
		pkg = pkgcache[DSO]
	} else {
		cmd = pkg_info_cmd " -Fe " shquote(DSO) " 2>/dev/null"
		if ((cmd | getline pkg) < 0) {
			close(cmd)
			return 0
		}
		close(cmd)
		pkgcache[DSO] = pkg
	}
	if (pkg == "")
		return 0
	found=0
	while ((getline < depends_file) > 0) {
		if ($3 == pkg) {
			found=1
			if ($1 != "full")
				continue
			close(depends_file)
			return 0
		}
	}
	if (found)
		print DSO ": " pkg " is not a runtime dependency"
	close(depends_file)
}

function checkshlib(DSO,	needed, found) {
	cmd = "otool -XL " shquote(DSO) " 2>/dev/null"
	while ((cmd | getline) > 0) {
		needed[$1] = ""
	}
	close(cmd)
	ndirs = split(cross_destdir ":" destdir, check_dirs, ":")
	for (lib in needed) {
		#
		# Ensure we don't have any WRKDIR references.
		#
		if (lib == wrkdir ||
		    substr(lib, 1, length(wrkdir) + 1) == wrkdir "/")
			print DSO ": path relative to WRKDIR: " lib

		#
		# Ensure there are no relative paths.
		#
		if (substr(lib, 1, 1) != "/")
			print DSO ": relative library path: " lib

		#
		# Check destination dirs for library existence.  If found in a
		# system path (cross_destdir is somewhat confusing but if set
		# it points to the populated cross destdir, otherwise we are
		# checking '/') then check_pkg() ensures it is a runtime dep.
		#
		for (i = 1; i <= ndirs; i++) {
			libfile = check_dirs[i] lib
			if (!(libfile in libcache))
				libcache[libfile] = system("test -f " \
							   shquote(libfile))
			if (libcache[libfile] == 0) {
				check_pkg(lib)
				found = 1
				break
			}
		}
		if (found == 0)
			print DSO ": missing library: " lib
	}
}

BEGIN {
	cross_destdir = ENVIRON["CROSS_DESTDIR"]
	destdir = ENVIRON["DESTDIR"]
	wrkdir = ENVIRON["WRKDIR"]
	pkg_info_cmd = ENVIRON["PKG_INFO_CMD"]
	depends_file = ENVIRON["DEPENDS_FILE"]
}

{ checkshlib($0); }
