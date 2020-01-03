# $NetBSD: options.mk,v 1.4 2020/01/03 19:23:27 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bison
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

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
