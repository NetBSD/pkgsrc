# $NetBSD: options.mk,v 1.6 2022/07/05 00:15:09 brook Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.bison
PKG_SUPPORTED_OPTIONS=	nls
# avoid suggesting nls on macOS/x86_64 versions where bison will crash
# schmonz reports 11.6 crashes, earlier likely doesn't, 12.0.1 doesn't
.if ${OPSYS} != Darwin || (${OPSYS} == Darwin && ${OPSYS_VERSION} > 110600)
PKG_SUGGESTED_OPTIONS=  nls
.endif

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

###
### NLS support
###
.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
