# $NetBSD: options.mk,v 1.19 2019/01/15 15:48:17 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tin
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	curses termcap # wide-curses removed, see below
PKG_SUPPORTED_OPTIONS=		canlock icu inet6 nls tin-use-inn-spool
PKG_SUGGESTED_OPTIONS=		canlock inet6 nls termcap # see PR #51819
# untested
#PKG_SUPPORTED_OPTIONS+=	socks

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcanlock)
.include "../../news/libcanlock/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cancel-locks
.endif

# Option wide-curses removed
# Use curses option and set CURSES_DEFAULT in mk.conf to select type
.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-screen=${CURSES_TYPE}
CONFIGURE_ARGS+=	--with-curses-dir=${BUILDLINK_PREFIX.curses}
.endif

.if !empty(PKG_OPTIONS:Mtermcap)
.include "../../mk/termcap.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

PLIST_VARS+=	nls
.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=	yes
.include "../../devel/gettext-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
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

#.if !empty(PKG_OPTIONS:Msocks)
#.include "../../net/dante/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-socks=${BUILDLINK_PREFIX.dante}
#.endif
