!/subdir\('[a-zA-Z0-9_-]*'\)/ {
	print
}

/subdir\('gst-libs'\)/ {
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
