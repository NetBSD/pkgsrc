# $NetBSD: options.mk,v 1.22 2023/01/25 18:06:41 micha Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tin
PKG_OPTIONS_REQUIRED_GROUPS=	display
PKG_OPTIONS_GROUP.display=	curses termcap
PKG_SUPPORTED_OPTIONS=		canlock icu inet6 nls tin-use-inn-spool tls
# curses(configured to curses) still does not work on NetBSD, see PR #51819
# Suggest termcap instead of curses.
PKG_SUGGESTED_OPTIONS=		canlock inet6 nls termcap tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcanlock)
.include "../../news/libcanlock/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cancel-locks
.endif

# Use curses option and CURSES_DEFAULT in mk.conf to select type
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

.if !empty(PKG_OPTIONS:Mtls)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-nntps=openssl
.endif
