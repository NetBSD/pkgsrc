# $NetBSD: help.awk,v 1.7 2007/01/08 02:27:05 rillig Exp $
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
	ignore_this_line = no;
	ignore_next_empty_line = no;

	delete lines;		# the collected lines
	relevant = no;		# are the current lines relevant?
	nlines = 0;		# the number of lines collected so far
	comment_lines = 0;	# the number of comment lines so far
	print_noncomment_lines = yes; # for make targets, this isn't useful
}

always {
	ignore_this_line = (ignore_next_empty_line && $0 == "#");
}

# There is no need to print the RCS Id, since the full pathname
# is prefixed to the file contents.
/^#.*\$.*\$$/ {
	ignore_this_line = yes;
	ignore_next_empty_line = yes;
}

# The lines containing the keywords should also not appear in
# the output for now. This decision is not final since it may
# be helpful for the user to know by which keywords a topic
# can be reached.
($1 == "#" && $2 == "Keywords:") {
	for (i = 3; i <= NF; i++) {
		w = ($i == toupper($i)) ? tolower($i) : $i;
		if (w == lctopic) {
			relevant = yes;
		}
	}
	ignore_this_line = yes;
	ignore_next_empty_line = yes;
}

($0 == "#") {
	ignore_next_empty_line = no;
}

(!ignore_this_line) {
	lines[nlines++] = $0;
}

# Check whether the current line contains a keyword. Such a keyword must
# be all-lowercase (make targets) or all-uppercase (variable names).
# Everything else is assumed to belong to the explaining text.
#
NF >= 2 {
	w1 = ($1 == tolower($1)) ? toupper($1) : $1;
	w2 = ($2 == tolower($2)) ? toupper($2) : $2;

	if ((w1 == uctopic"?=") ||
	    (w1 == uctopic"=") ||
	    (index(w1, "#"uctopic"=") == 1) ||
	    (index(w1, "#"uctopic"?=") == 1) ||
	    (last_line_was_empty && w1 == "#" && (w2 == uctopic ||
						  w2 == uctopic":"))) {
		relevant = yes;
	}
}

# Don't print the implementation of make targets.
$1 == uctopic":" {
	print_noncomment_lines = no;
}

$1 == "#" {
	comment_lines++;
}

# Help topics are separated by either completely empty lines or by the
# end of a file. When here have been enough comment lines, the topic is
# considered worth printing.
#
/^$/ || last_fname != FILENAME {
	if (relevant && comment_lines > 2) {
		found_anything = yes;
		print "===> "last_fname":";
		for (i = 0; i < nlines; i++) {
			if (!print_noncomment_lines || (lines[i] ~ /^#/))
				print lines[i];
		}
	}

	ignore_next_empty_line = yes;
	delete lines;
	relevant = no;
	nlines = 0;
	comment_lines = 0;
	print_noncomment_lines = yes;
}

always {
	last_line_was_empty = (/^#$/ || /^$/);
	last_fname = FILENAME;
}

END {
	if (!found_anything) {
		print "No help found for "topic".";
	}
}
