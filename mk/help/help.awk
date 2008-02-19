# $NetBSD: help.awk,v 1.23 2008/02/19 22:12:00 rillig Exp $
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
	ignore_this_line = no;
	ignore_next_empty_line = no;
	ignore_this_section = no;

	delete lines;		# the collected lines
	nlines = 0;		# the number of lines collected so far
	delete keywords;	# the keywords for this paragraph
	delete all_keywords;	# all keywords that appear anywhere
	comment_lines = 0;	# the number of comment lines so far
	print_noncomment_lines = yes; # for make targets, this isn't useful
	print_index = (topic == ":index");
				# whether to print only the list of keywords
}

# Help topics are separated by either completely empty lines or by the
# end of a file or by the end of all files. When there have been enough
# comment lines, the topic is considered worth printing.
#
function end_of_topic() {

	if (comment_lines <= 2 || ignore_this_section) {
		cleanup();
		return;
	}

	for (k in keywords)
		all_keywords[k]++;

	relevant = (topic in keywords || lctopic in keywords || uctopic in keywords || topic == ":all");
	if (relevant && !print_index) {

		if (found_anything)
			print "";
		found_anything = yes;

		kw = "";
		for (i in keywords)
			kw = kw " " i;
		print "===> "last_fname " (keywords:" kw "):";

		for (i = 0; i < nlines; i++) {
			if (print_noncomment_lines || (lines[i] ~ /^#/))
				print lines[i];
		}
	}
	cleanup();
}

function cleanup() {
	ignore_next_empty_line = yes;
	delete lines;
	nlines = 0;
	delete keywords;
	comment_lines = 0;
	print_noncomment_lines = yes;
	ignore_this_section = no;
}

always {
	ignore_this_line = (ignore_next_empty_line && $0 == "#") || $0 == "";
	ignore_next_empty_line = no;
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

$1 == "#" && $2 == "Copyright" {
	ignore_this_section = yes;
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
NF >= 1 && !/^[\t.]/ && !/^#*$/ {
	w = $1 == "#" ? $2 : $1;

	# Reduce FOO.<param> and FOO.${param} to FOO.
	sub(/\.[<$].*[>}]$/, "", w);

	if (w ~ /\+=$/) {
		# Appending to a variable is usually not a definition.

	} else if (w != toupper(w) && w != tolower(w)) {
		# Words in mixed case are not taken as keywords. If you
		# want them anyway, list them in a "Keywords:" line.

	} else if (w == tolower(w) && !(w ~ /:$/)) {
		# Lower-case words (often make targets) must be followed
		# by a colon to be recognized as keywords.

	} else if (w == toupper(w) && w ~ /:$/) {
		# Upper-case words ending with a colon are probably not
		# make targets, so ignore them.

	} else if (w !~ /^[A-Za-z].*[0-9A-Za-z](:|\?=|=)?$/) {
		# Keywords must start with a letter and end with a letter
		# or digit.

	} else if (w ~ /^(FIXME|TODO|XXX):?$/) {
		# These are not keywords.

	} else {
		sub(/^#[ \t]*/, "", w);
		sub(/(:|\?=|=)$/, "", w);
		sub(/:$/, "", w);
		if (w != "") {
			keywords[w] = yes;
		}
	}
}

# Don't print the implementation of make targets.
$1 ~ /:$/ {
	print_noncomment_lines = no;
}

$1 == "#" {
	comment_lines++;
}

/^$/ || last_fname != FILENAME {
	end_of_topic();
}

always {
	last_fname = FILENAME;
}

END {
	end_of_topic();
	if (print_index) {
		for (k in all_keywords) {
			print all_keywords[k] "\t" k;
		}
	} else if (!found_anything) {
		print "No help found for "topic".";
	}
}
