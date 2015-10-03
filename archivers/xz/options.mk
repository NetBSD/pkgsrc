# $NetBSD: options.mk,v 1.2 2015/10/03 12:28:45 tnn Exp $

CHECK_BUILTIN.gettext:=yes
.include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=no

PKG_OPTIONS_VAR=	PKG_OPTIONS.xz
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=
.if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=	nls
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=		yes
CONFIGURE_ARGS+=	--enable-nls
USE_TOOLS+=		msgfmt msgmerge xgettext
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
