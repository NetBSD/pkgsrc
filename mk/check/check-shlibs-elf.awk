function shquote(IN, out) {
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

function check_pkg(DSO, pkg) {
	if (destdir == "")
		return 0
	cmd = pkg_info_cmd " -Fe " shquote(DSO) " 2> /dev/null"
	if ((cmd | getline pkg) < 0) {
		close(cmd)
		return 0
	}
	close(cmd)
	if (pkg == "")
		return 0
	while ((getline < depends_file) > 0) {
		if ($3 == pkg) {
			if ($1 != "full")
				print DSO ": " pkg " is not a runtime dependency"
			close(depends_file)
			return 0
		}
	}
	# Not yet:
	# print DSO ": " pkg " is not a dependency"
	close(depends_file)
}

function checkshlib(DSO, needed, rpath, found, dso_rath, got_rpath) {
	cmd = readelf " -Wd " shquote(DSO) " 2> /dev/null"
	while ((cmd | getline) > 0) {
		if ($2 == "(RPATH)") {
			sub("^[[:space:]]*0[xX][[:xdigit:]]+[[:space:]]+\\(RPATH\\)[[:space:]]+Library rpath: \\[", "")
			dso_rpath = substr($0, 1, length($0) - 1)
			if (length(system_rpath) > 0)
				split(dso_rpath ":" system_rpath, rpath, ":")
			else
				split(dso_rpath, rpath, ":")
			got_rpath = 1
		}
		if ($2 == "(NEEDED)") {
			sub("^[[:space:]]*0[xX][[:xdigit:]]+[[:space:]]+\\(NEEDED\\)[[:space:]]+Shared library: \\[", "")
			needed[substr($0, 1, length($0) - 1)] = ""
		}
	}
	if (!got_rpath)
		split(system_rpath, rpath, ":")
	close(cmd)
	for (p in rpath) {
		if (rpath[p] == wrkdir ||
		    substr(rpath[p], 1, length(wrkdir) + 1) == wrkdir "/") {
			print DSO ": rpath relative to WRKDIR"
		}
	}
	for (lib in needed) {
		for (p in rpath) {
			if (!system("test -f " shquote(cross_destdir rpath[p] "/" lib))) {
				check_pkg(rpath[p] "/" lib)
				found = 1
				break
			}
			if (!system("test -f " shquote(destdir rpath[p] "/" lib))) {
				found = 1
				break
			}
		}
		if (found == 0)
			print DSO ": missing library: " lib;
	}
	delete rpath
	delete needed
}

BEGIN {
	system_rpath = ENVIRON["PLATFORM_RPATH"]
	cross_destdir = ENVIRON["CROSS_DESTDIR"]
	destdir = ENVIRON["DESTDIR"]
	readelf = ENVIRON["PLATFORM_READELF"]
	wrkdir = ENVIRON["WRKDIR"]
	pkg_info_cmd = ENVIRON["PKG_INFO_CMD"]
	depends_file = ENVIRON["DEPENDS_FILE"]
	if (readelf == "")
		readelf = "readelf"
}

{ checkshlib($0); }
