BEGIN {
	print "# $Net" "BSD$"
	print ""
}

# Sanitise all lines.
{
	# Ensure lines are correctly delimited, e.g. rev="foo" -> rev = "foo"
	gsub(/=/, " = ")

	# Extract just the string inside quotemarks.
	for (i = 1; i <= NF; i++) {
		gsub(/^[^"]*"/, "", $i)
		gsub(/"[^"]*$/, "", $i)
	}
}

# Assumes "name" comes before "source".  This is currently true.
/^name =/ {
	path = $3
}

/^source =/ {
	for (i = 1; i <= NF; i++) {
		if ($i == "git" && $(i + 1) == "=") {
			url = $(i + 2)
			name = substr(url, match(url, /[^\/]*$/))
		}
		if ($i == "rev" && $(i + 1) == "=") {
			rev = $(i + 2)
		}
	}
	print "TS_FILES+=	" name " " rev " " url " " path
}

END {
	print ""
	print ".for name rev url path in ${TS_FILES}"
	print "TS_DISTFILE:=		${name}-${rev}.tar.gz"
	print "TS_DISTFILES:=		${TS_DISTFILES} ${TS_DISTFILE}"
	print "SITES.${TS_DISTFILE}=	-${url}/archive/${rev}.tar.gz -${url}/-/archive/${rev}.tar.gz"
	print ".endfor"
	print "DISTFILES:=		${DEFAULT_DISTFILES} ${TS_DISTFILES}"
}
