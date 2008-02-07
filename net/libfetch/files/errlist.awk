BEGIN {
	printf "static struct fetcherr %s[] = {\n", variable
}

/^#/	{ next }

{	printf "\t{ %d, FETCH_%s, \"%s\" },\n", $1, $2, $3 }

END {
	printf "\t{ -1, FETCH_UNKNOWN, \"Unknown %s error\" }\n", protocol
	printf "};\n"
}
