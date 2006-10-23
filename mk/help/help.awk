# $NetBSD: help.awk,v 1.1 2006/10/23 14:40:15 rillig Exp $
#

BEGIN {
	no = 0; yes = 1;
	hline = "===============";
	hline = hline hline hline hline hline;
	found = no; var = no; comment = no; n = 0;
	rcsid = "";
	last_line_was_rcsid = no;
	last_line_was_empty = yes;
	topic = ENVIRON["TOPIC"];
	uctopic = toupper(topic);
}

/.*/ {
	if ($0 ~ /^#.*\$.*\$$/) {
		rcsid = $0;
		last_line_was_rcsid = yes;
	} else {
		if (last_line_was_rcsid && $0 == "#") {
			# Skip this line
		} else if ($0 == "") {
			# Skip completely empty lines, too.
		} else {
			lines[n++] = $0;
		}
		last_line_was_rcsid = no;
	}
}

/./ {
	# When looking for "configure", catch lines that contain
	# "configure" and "CONFIGURE", but not "Configure".
	w1 = ($1 == tolower($1)) ? toupper($1) : $1;
	w2 = ($2 == tolower($2)) ? toupper($2) : $2;

	if ((w1 == uctopic"?=") ||
	    (w1 == "#"uctopic"=") ||
	    (w1 == "#" && last_line_was_empty &&
	     (w2 == uctopic || w2 == uctopic":"))) {
		var = 1;
	}
}

/^#/ {
	comment = 1;
}

/^$/ {
	if (var && comment) {
		found = yes;
		print hline;
		if (rcsid != "") { print rcsid; print "#"; }
		for (i = 0; i < n; i++) { print lines[i]; }
	}
	var = no; comment = no; n = 0;
}

/./ {
	last_line_was_empty = no;
}
/^#$/ || /^$/ {
	last_line_was_empty = yes;
}

END {
	if (found) {
		print hline;
	} else {
		print "No help found for "topic".";
	}
}
