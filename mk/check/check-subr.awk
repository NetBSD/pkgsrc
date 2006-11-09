# $NetBSD: check-subr.awk,v 1.1 2006/11/09 14:36:18 rillig Exp $
#
# This file contains shell functions that are used by the various awk
# programs that check things in pkgsrc. All these programs must be
# called with the following environment variables set:
#
# CK_FNAME
#	The name of the file that is checked. Since awk interprets
#	command line arguments in a weird way, the input file must be
#	passed via stdin.
#
# CK_PROGNAME
#	The program name to be used in diagnostic messages.
#

BEGIN {
	cs_exitcode = 0;
	cs_fname = ENVIRON["CK_FNAME"];
	cs_progname = ENVIRON["CK_PROGNAME"];
	cs_last_heading = "";
	cs_hline = "=========================";
	cs_hline = cs_hline cs_hline cs_hline;
	no = 0;
	yes = 1;
}

function cs_error_heading(new_heading) {
	if (new_heading != cs_last_heading) {
		cs_last_heading = new_heading;
		cs_error_msg("=> " new_heading);
	}
}

function cs_warning_heading(new_heading) {
	if (new_heading != cs_last_heading) {
		cs_last_heading = new_heading;
		cs_warning_msg("=> " new_heading);
	}
}

function cs_error_msg(msg) {
	printf("ERROR: [%s] %s\n", cs_progname, msg) > "/dev/stderr";
	cs_exitcode = 1;
}

function cs_warning_msg(msg) {
	printf("WARNING: [%s] %s\n", cs_progname, msg) > "/dev/stderr";
}

function cs_explain(msg) {
	printf("\nExplanation:\n%s\n%s%s\n\n", cs_hline, msg, cs_hline) > "/dev/stderr";
}

function cs_exit() {
	exit(cs_exitcode);
}
