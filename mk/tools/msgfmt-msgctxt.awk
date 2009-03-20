# $NetBSD: msgfmt-msgctxt.awk,v 1.1 2009/03/20 16:13:02 joerg Exp $
#
# Simple awk script to strip out .po entries with "msgctxt" or "#~|", so the
# resultant file can be handled by the msgfmt 0.14.x.
{
if (/^$/) { entry_end(); }
else if ($1 == "msgctxt" || $2 == "msgctxt") { skip = 1; }
else if ($1 == "#~|") { skip = 1; }
else { entry = entry $0 "\n" }
}

END { entry_end(); }

function entry_end() {
    if (!skip)
	print entry;
    entry = "";
    skip = 0;
}
