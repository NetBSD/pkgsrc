# $NetBSD: help.awk,v 1.35 2020/03/30 06:21:52 rillig Exp $
#

# This program extracts the inline documentation from *.mk files.
#
# usage: env TOPIC="topic" awk help.awk file...
#

BEGIN {
	no = 0; yes = 1;

	debug = ENVIRON["HELP_DEBUG"] != "";
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
	delete all_appearances;	# all files where the topic appears as text
}

# Help topics are separated by either completely empty lines or by the
# end of a file or by the end of all files. When there have been enough
# comment lines, the topic is considered worth printing.
#
function end_of_topic() {

	if (comment_lines <= 2 || ignore_this_section) {
		if (array_is_empty(keywords)) {
			dprint("Ignoring section because of missing keywords.");
		} else if (comment_lines <= 2) {
			dprint("Ignoring section because of too small comment.");
		} else {
			dprint("Ignoring section because of a previous decision.");
		}
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

		print "===> " last_fname " (keywords:" sorted_keys(keywords, " ") "):";

		for (i = 0; i < nlines; i++) {
			if (print_noncomment_lines || (lines[i] ~ /^#/))
				print lines[i];
		}
	}
	cleanup();
}

# Returns the sorted keys of the array, each prefixed by the prefix.
function sorted_keys(array, prefix,   elem, list, listlen, i, j, tmp, result) {
	listlen = 0;
	for (elem in array)
		list[listlen++] = elem;

	for (i = 0; i < listlen; i++) {
		for (j = i + 1; j < listlen; j++) {
			if (list[j] < list[i]) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}

	result = "";
	for (i = 0; i < listlen; i++) {
		result = result prefix list[i];
	}
	return result;
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

function dprint(msg) {
	if (!debug) return;
	print(FILENAME ":" FNR ": " msg);
}

function dprint_skip(word, reason) {
	if (!debug) return;
	print(FILENAME ":" FNR ": \"" word "\" is no keyword because " reason);
}

function array_is_empty(arr,   i, empty) {
	empty = yes;
	for (i in arr) {
		empty = no;
		break;
	}
	return empty;
}

{
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
		dprint("Adding keyword \"" w "\"");
	}
	ignore_this_line = yes;
	ignore_next_empty_line = yes;
}

($0 == "#") {
	ignore_next_empty_line = no;
}

$1 == "#" && $2 == "Copyright" {
	dprint("Ignoring the section because it contains \"Copyright\".");
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
NF >= 1 && !/^[\t.]/ && !/^#*$/ && !/^#\t\t/ {
	w = ($1 ~ /^#[A-Z]/) ? substr($1, 2) : ($1 == "#") ? $2 : $1;

	# Reduce VAR.<param>, VAR.${param} and VAR.* to VAR.
	sub(/\.[<$].*[>}]$/, "", w);
	sub(/\.\*$/, "", w);

	if (w ~ /\+=$/) {
		# Appending to a variable is usually not a definition.
		dprint_skip(w, "it is appended to a variable");

	} else if (w != toupper(w) && w != tolower(w)) {
		# Words in mixed case are not taken as keywords. If you
		# want them anyway, list them in a "Keywords:" line.
		dprint_skip(w, "it is mixed case");

	} else if (w !~ /^[A-Za-z][-0-9A-Z_a-z]*[0-9A-Za-z](:|\?=|=)?$/) {
		# Keywords must consist only of letters, digits, hyphens
		# and underscores; except for some trailing type specifier.
		dprint_skip(w, "it contains special characters");

	} else if (NF > 2 && w == tolower(w)) {
		dprint_skip(w, "it is lowercase and followed by other words");

	} else if (/^#[ \t][ \t]/ && w == tolower(w)) {
		dprint_skip(w, "it is indented by several spaces");

	} else if (w == tolower(w) && w !~ /:$/ && $0 != "# " w) {
		# Lower-case words (often make targets) must be followed
		# by a colon to be recognized as keywords.
		dprint_skip(w, "it is lowercase and not followed by a colon");

	} else if (w == toupper(w) && w ~ /:$/) {
		# Upper-case words ending with a colon are probably not
		# make targets, so ignore them. Common cases are tags
		# like FIXME and TODO.
		dprint_skip(w, "it is uppercase and followed by a hyphen");

	} else {
		sub(/^#[ \t]*/, "", w);
		sub(/(:|\?=|=)$/, "", w);
		sub(/:$/, "", w);
		if (w != "") {
			if (debug) dprint("Adding keyword \"" w "\"");
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

index(tolower($0), topic) != 0 {
	all_appearances[FILENAME] = yes;
}

{
	last_fname = FILENAME;
}

END {
	end_of_topic();
	if (print_index) {
		print "Available help topics:";
		print sorted_keys(all_keywords, "\n");
	} else if (!found_anything) {
		appearances = sorted_keys(all_appearances, "\n");
		if (appearances != "") {
			print "No help found for " topic ", but it appears in:\n" appearances;
		} else {
			print "No help found for " topic ".";
		}
	}
}
