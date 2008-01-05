# $NetBSD: help.awk,v 1.19 2008/01/05 17:01:23 rillig Exp $
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
	this_line_maybe_definition = yes;
	ignore_this_line = no;
	ignore_next_empty_line = no;

	delete lines;		# the collected lines
	nlines = 0;		# the number of lines collected so far
	delete keywords;	# the keywords for this paragraph
	comment_lines = 0;	# the number of comment lines so far
	print_noncomment_lines = yes; # for make targets, this isn't useful
}

# Help topics are separated by either completely empty lines or by the
# end of a file or by the end of all files. When there have been enough
# comment lines, the topic is considered worth printing.
#
function end_of_topic(		kw, relevant) {
	kw = "";
	for (i in keywords) {
		kw = kw " " i;
	}
	relevant = (topic in keywords || lctopic in keywords || uctopic in keywords);
	if (relevant && comment_lines > 2) {
		if (found_anything)
			print "";
		found_anything = yes;
		print "===> "last_fname " (keywords:" kw "):";
		for (i = 0; i < nlines; i++) {
			if (print_noncomment_lines || (lines[i] ~ /^#/))
				print lines[i];
		}
	}

	ignore_next_empty_line = yes;
	delete lines;
	nlines = 0;
	delete keywords;
	comment_lines = 0;
	print_noncomment_lines = yes;
}

always {
	ignore_this_line = (ignore_next_empty_line && $0 == "#") || $0 == "";
	ignore_next_empty_line = no;
	this_line_is_definition = no;
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
		sub(/,$/, "", w);
		keywords[w] = yes;
	}
	ignore_this_line = yes;
	ignore_next_empty_line = yes;
}

($0 == "#") {
	ignore_next_empty_line = no;
}

# Don't show the user the definition of make targets, since they are
# usually not interesting enough. This allows the comments to reach
# until the line directly above the target definition.
#
$1 ~ /:$/ && $2 == ".PHONY" {
	end_of_topic();
}

(!ignore_this_line) {
	lines[nlines++] = $0;
}

# Check whether the current line contains a keyword. Such a keyword must
# be all-lowercase (make targets) or all-uppercase (variable names).
# Everything else is assumed to belong to the explaining text.
#
NF >= 1 {
	# Reduce FOO.<param> and FOO.${param} to FOO.
	w1 = $1; sub(/\.[<$].*[>}]$/, "", w1);
	w2 = $2; sub(/\.[<$].*[>}]$/, "", w2);

	# Convert all-lowercase words to all-uppercase.
	w1 = (w1 == tolower(w1)) ? toupper(w1) : w1;
	w2 = (w2 == tolower(w2)) ? toupper(w2) : w2;

	this_line_is_definition = (w1 == toupper($1)) && (w2 == toupper($2));

	w = (w1 == "#") ? w2 : w1;
	if ((w1 == uctopic"?=") ||
	    (w1 == uctopic"=") ||
	    (index(w1, "#"uctopic"=") == 1) ||
	    (index(w1, "#"uctopic"?=") == 1) ||
	    (this_line_maybe_definition &&
	        (w == uctopic || w == uctopic":"))) {
		keywords[w] = yes;
	}
}

# Don't print the implementation of make targets.
$1 == uctopic":" {
	print_noncomment_lines = no;
}

$1 == "#" {
	comment_lines++;
}

/^$/ || last_fname != FILENAME {
	end_of_topic();
}

always {
	# Note: The first "this" actually means the next line.
	this_line_maybe_definition = (/^#$/ || /^$/) || this_line_is_definition;
	last_fname = FILENAME;
}

END {
	end_of_topic();
	if (!found_anything) {
		print "No help found for "topic".";
	}
}
