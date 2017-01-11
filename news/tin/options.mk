# $NetBSD: options.mk,v 1.17 2017/01/11 02:15:56 roy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tin
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	curses wide-curses termcap
PKG_SUPPORTED_OPTIONS=		icu inet6 tin-use-inn-spool
PKG_SUGGESTED_OPTIONS=		inet6 termcap # see PR #51819
# untested
#PKG_SUPPORTED_OPTIONS+=	socks

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses) || !empty(PKG_OPTIONS:Mwide-curses)
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=${CURSES_TYPE}
CONFIGURE_ARGS+=	--with-curses-dir=${BUILDLINK_PREFIX.curses}
.else
.include "../../mk/termcap.buildlink3.mk"
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
.include "../../net/dante/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks=${BUILDLINK_PREFIX.dante}
.endif
