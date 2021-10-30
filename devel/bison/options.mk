# $NetBSD: options.mk,v 1.5 2021/10/30 07:46:10 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bison
PKG_SUPPORTED_OPTIONS=	nls
# TODO: avoid suggesting nls on macOS/x86_64 versions where bison will crash
# schmonz reports 11.6 crashes, earlier likely doesn't, 12.0.1 doesn't
PKG_SUGGESTED_OPTIONS=  nls

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
