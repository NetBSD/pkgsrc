# $NetBSD: options.mk,v 1.10 2008/07/14 10:09:56 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tin
PKG_SUPPORTED_OPTIONS=		icu inet6 tin-use-inn-spool
PKG_OPTIONS_OPTIONAL_GROUPS=	display
PKG_OPTIONS_GROUP.display=	curses ncurses ncursesw
PKG_SUGGESTED_OPTIONS=		curses
# untested
#PKG_SUPPORTED_OPTIONS+=	socks

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses)
.  include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=curses
.  if !empty(BUILDLINK_PREFIX.curses)
CONFIGURE_ARGS+=	--with-curses-dir=${BUILDLINK_PREFIX.curses}
.  endif
.endif

.if !empty(PKG_OPTIONS:Mncurses)
.  include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=ncurses
CONFIGURE_ARGS+=	--with-curses-dir=${BUILDLINK_PREFIX.ncurses}
.endif

.if !empty(PKG_OPTIONS:Mncursesw)
.  include "../../devel/ncursesw/buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=ncursesw
CONFIGURE_ARGS+=	--with-curses-dir=${BUILDLINK_PREFIX.ncursesw}
# XXX: NetBSD's wide curses are not accepted, because the configure
# script doesn't find the proper headers.
# This could be a bug in the buildlink framework for wide curses.
# The next line is a workaround until someone(TM) finds time to
# investigate this.
USE_BUILTIN.ncursesw=	no
.endif

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mtin-use-inn-spool)
BUILD_DEFS+=		INN_DATA_DIR VARBASE
INN_DATA_DIR?=		${VARBASE}/news
CONFIGURE_ARGS+=	--with-inews-dir=${PREFIX}/inn/bin \
			--with-libdir=${INN_DATA_DIR}/db \
			--with-spooldir=${INN_DATA_DIR}/spool/articles \
			--with-nov-dir=${INN_DATA_DIR}/spool/overview
.else
CONFIGURE_ARGS+=	--enable-nntp-only
.endif

.if !empty(PKG_OPTIONS:Msocks)
.include "../../net/socks5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks5=${BUILDLINK_PREFIX.socks5}
.endif
