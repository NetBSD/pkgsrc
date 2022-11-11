BEGIN { print "# $Net" "BSD$"; }
/(^|\n)source =/ {
	for (i = 1; i <= NF; i++) {
		sub("\"","")
		sub(",","")
		sub("}","")
		sub("{","")
		if ($i ~ /^https/) {
			name = gensub(".*/", "", "g", $i);
			if (name == "tree-sitter-git-diff")
				name = "tree-sitter-diff"
			url = $i
		}
		if ($i ~ /[a-f0-9]{40}/)
			vers=$i
	}
	print "TREESITTER_DISTFILES+=\t\t" name "-" vers ".tar.gz"
	print "SITES." name "-" vers ".tar.gz= \\\n" "\t\t-" url "/archive/" vers ".tar.gz\n"
}
