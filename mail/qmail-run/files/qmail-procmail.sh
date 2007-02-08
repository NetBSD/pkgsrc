#!@SH@
# Copyright (c) 1998-2001 Software in the Public Interest
# <http://www.debian.org/>
# Written by Philip Hands. Distributed under the GNU GPL.
# Modified slightly by Dave Sill.

@LOCALBASE@/bin/preline @LOCALBASE@/bin/procmail && exit 0

# check if procmail returned EX_TEMPFAIL (75)
[ $? = 75 ] && exit 111

# otherwise return a permanent error
exit 100
