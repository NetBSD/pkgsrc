# AWK functions for working on pkgsrc

#use "pkgsrc-dewey.awk"
#use "glob.awk"

# return a position where version begins
function pkgver_position (pkgname,            idx){
	if (match(pkgname, /<|>|=/))
		return RSTART
	else
		return match(pkgname, /-(\[[^\[\]]*\]|[^-])*$/)
}

# strip version from PKGNAME
function pkgname2pkgbase (pkgname){
	return substr(pkgname, 1, pkgver_position(pkgname)-1)
}

# extract version from PKGNAME, e.g. -1.2.3, -[0-9]*, >=1.0 etc.
function pkgname2version (pkgname,       pos){
	pos = pkgver_position(pkgname)

	if (substr(pkgname, pos, 1) == "-")
		return substr(pkgname, pos+1)
	else
		return substr(pkgname, pos)
}

# remove ../../ prefix, extra spaces and ending /
function normalize_pkgpath (pkgpath){
	sub(/^[.][.]\/[.][.]\//, "", pkgpath)
	sub(/^ +/, "", pkgpath)
	sub(/ +$/, "", pkgpath)
	sub(/\/+$/, "", pkgpath)
	return pkgpath
}

# Source dependency to PKGPATH
# checkperms>=1.1:../../sysutils/checkperms/ to sysutils/checkperms
function src_depend2pkgpath (dep){
	sub(/^[^:]*:/, "", dep)
	return normalize_pkgpath(dep)
}

# returns 1 if pkgname1 is greater than pkgname2
function pkgname_gt_pkgname (pkgname1, pkgname2,            ver1,ver2){
	ver1 = pkgname2version(pkgname1)
	ver2 = pkgname2version(pkgname2)

	return dewey_cmp(ver1, ver2) == ">"
}

# ex: dewey_match(1.2.3, ">=1.0")
function pattern_match (ver, pattern,           i,j,k){
	while (match(pattern, /(>|<|=|>=|<=)[^<=>]*/)){
		assert(RSTART == 1, "failed in dewey_match() function")
		i = substr(pattern, RSTART, RLENGTH)
		j = substr(pattern, RSTART + RLENGTH)
		k = match(i, /[0-9]/)

		if (!dewey_test(ver, substr(i,k), substr(i,1,k-1)))
			return 0

		pattern = j
	}

	if (pattern == "" || pattern == "[0-9]*")
		return 1

	return glob(ver, pattern)
}
