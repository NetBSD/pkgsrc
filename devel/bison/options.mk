# $NetBSD: options.mk,v 1.1 2019/10/23 11:58:01 triaxx Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bison
PKG_SUPPORTED_OPTIONS=	nls

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

###
### NLS support
###
.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
CONFIGURE_ARG+=		--enable-nls
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARG+=		--disable-nls
.endif
