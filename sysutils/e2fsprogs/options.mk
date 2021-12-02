# $NetBSD: options.mk,v 1.1 2021/12/02 17:59:05 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.e2fsprogs
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

###
### NLS support
###
.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt msgmerge xgettext
CONFIGURE_ARGS+=	--enable-nls
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
