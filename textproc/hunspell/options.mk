# $NetBSD: options.mk,v 1.5 2013/08/27 22:11:20 richard Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hunspell
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		# empty

.include "../../mk/bsd.options.mk"

USE_NCURSES=	yes

###
### Wide curses support; otherwise, default to using narrow curses.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-9].*-*)
   CONFIGURE_ENV+=	ac_cv_lib_curses_tparm=yes
.  include "../../mk/curses.buildlink3.mk"
.else
.  if !empty(PKG_OPTIONS:Mwide-curses)
.    include "../../devel/ncursesw/buildlink3.mk"
CPPFLAGS.SunOS+=	-D_XPG6
.  else
.    include "../../devel/ncurses/buildlink3.mk"
.  endif
.endif
