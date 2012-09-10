# $NetBSD: msgfmt-msgctxt.awk,v 1.3 2012/09/10 16:07:44 adam Exp $
#
# Simple awk script to strip out .po entries with "msgctxt" or "#~|", so the
# resultant file can be handled by the msgfmt 0.14.x.
{
sub(/\r$/, "")
if (/^$/) { entry_end(); }
else if ($1 == "msgctxt" || $2 == "msgctxt") { skip = 1; }
else if ($1 == "#~") { skip = 1; }
else { entry = entry $0 "\n" }
}

END { entry_end(); }

function entry_end() {
    if (!skip)
	print entry;
    entry = "";
    skip = 0;
}
