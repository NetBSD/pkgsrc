# $NetBSD: curses.buildlink3.mk,v 1.5 2007/11/03 15:17:42 rillig Exp $
#
# This file should be included by Makefiles for packages that use curses.
# It checks whether a native curses implementation is available, or
# otherwise adds a dependency on ncurses.
#
# If a package genuinely requires ncurses, then it should directly include
# ncurses/buildlink3.mk instead of this file in the package Makefile and
# additionally set USE_NCURSES=yes.
#

.if !exists(/usr/include/curses.h) && \
    !exists(/usr/include/ncurses.h)
.  include "../../devel/ncurses/buildlink3.mk"
.else

# XXX this is ugly, but needed to get the BUILDLINK_TRANSFORM from builtin.mk;
# on Interix, libncurses is static yet libcurses (also ncurses) is shared
.  include "bsd.fast.prefs.mk"
.  if ${OPSYS} == "Interix"
.    include "../../devel/ncurses/buildlink3.mk"
.  endif

.endif
