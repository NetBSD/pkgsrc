# $NetBSD: generate.awk,v 1.1 2013/12/05 11:42:15 obache Exp $
#
# AWK script to replace @FONTDIR_ENTRIES@ with a list of <dir></dir>
# entries taken from the "entries" array.  We do variable replacement
# for ${LOCALBASE} and ${X11BASE} using the values of LOCALBASE and
# X11BASE that are passed to the script.
#

BEGIN {
	entries[0]  = "${X11BASE}/lib/X11/fonts"
	entries[1]  = "${LOCALBASE}/lib/X11/fonts"
	entries[2]  = "${LOCALBASE}/share/fonts"
	entries[3]  = "${LOCALBASE}/java/sun-6/lib/fonts"
	entries[4] = "${LOCALBASE}/Acrobat7/Resource/CIDFont"
	entries[5] = "${LOCALBASE}/Acrobat8/Adobe/Reader8/Resource/Font"
	entries[6] = "${LOCALBASE}/Acrobat9/Adobe/Reader9/Resource/Font"
	num_entries = 7

	LOCALBASE = ENVIRON["LOCALBASE"] ? ENVIRON["LOCALBASE"] : "/usr/pkg"
	X11BASE = ENVIRON["X11BASE"] ? ENVIRON["X11BASE"] : "/usr/X11R6"
}

/^@FONTDIR_ENTRIES@/ {
	for (i = 0; i < num_entries; i++) {
		entry = entries[i]
		sub("[$]{LOCALBASE}", LOCALBASE, entry)
		sub("[$]{X11BASE}", X11BASE, entry)
		print "	<dir>" entry "</dir>"
	}
	next
}
{ print }
