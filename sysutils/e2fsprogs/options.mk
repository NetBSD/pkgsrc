# $NetBSD: options.mk,v 1.2 2022/06/07 08:17:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.e2fsprogs
PKG_SUPPORTED_OPTIONS=	nls
# the option is broken - the .po files it wants to install are not generated
PKG_SUGGESTED_OPTIONS=	# nls

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
