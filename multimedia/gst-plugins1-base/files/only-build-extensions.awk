!/subdir([a-zA-Z0-9_-]*)/ {
	print
}

/subdir\('ext'\)/ {
	if (basedir == "ext") {
		print
	}
}

/subdir\('sys'\)/ {
	if (basedir == "sys") {
		print
	}
}
