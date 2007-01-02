# $NetBSD: help.awk,v 1.4 2007/01/02 22:54:54 rillig Exp $
#

# This program extracts the inline documentation from *.mk files.
#
# usage: env TOPIC="topic" awk help.awk file...
#

BEGIN {
	no = 0; yes = 1; always = 1;

	topic = ENVIRON["TOPIC"];
	uctopic = toupper(topic);
	lctopic = tolower(topic);

	found_anything = no;	# has some help text been found at all?
	last_fname = "";
	last_line_was_empty = yes;
	last_line_was_rcsid = no;
	ignore_next_empty_line = no;

	delete lines;		# the collected lines
	relevant = no;		# are the current lines relevant?
	nlines = 0;		# the number of lines collected so far
	comment_lines = 0;	# the number of comment lines so far
}

NF >= 1 {
	if ($0 ~ /^#.*\$.*\$$/) {
		last_line_was_rcsid = yes;
		ignore_next_empty_line = yes;
	} else {
		if ($1 == "#" && $2 == "Keywords:") {
			for (i = 3; i <= NF; i++) {
				w = ($i == toupper($1)) ? tolower($i) : $i;
				if (w == lctopic) {
					relevant = yes;
				}
			}
			ignore_next_empty_line = yes;
		} else if (ignore_next_empty_line && $0 == "#") {
			ignore_next_empty_line = no;
		} else {
			lines[nlines++] = $0;
		}
		last_line_was_rcsid = no;
	}
}

NF >= 2 {
	# When looking for "configure", catch lines that contain
	# "configure" and "CONFIGURE", but not "Configure".
	w1 = ($1 == tolower($1)) ? toupper($1) : $1;
	w2 = ($2 == tolower($2)) ? toupper($2) : $2;

	if ((w1 == uctopic"?=") || (w1 == uctopic"=") ||
	    (index(w1, "#"uctopic"=") == 1) ||
	    (index(w1, "#"uctopic"?=") == 1) ||
	    (w1 == "#" && last_line_was_empty &&
	     (w2 == uctopic || w2 == uctopic":"))) {
		relevant = 1;
	}
}

/^#/ {
	comment_lines++;
}

/^$/ || last_fname != FILENAME {
	if (relevant && comment_lines > 2) {
		found = yes;
		print "===> "last_fname":";
		for (i = 0; i < nlines; i++) {
			#print gensub(/^# ?/, "", "", lines[i]);
			print lines[i];
		}
	}
	relevant = no; comment_lines = 0; nlines = 0;
}

always {
	last_line_was_empty = (/^#$/ || /^$/);
	last_fname = FILENAME;
}

END {
	if (!found) {
		print "No help found for "topic".";
	}
}
