# $NetBSD: options.mk,v 1.9 2020/03/14 13:28:57 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmake
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

# Build NLS support only if a native implementation of gettext is available
# to avoid a circular dependency (gmake->gettext-tools->ncurses->gmake).
.include "../../devel/gettext-lib/builtin.mk"
.if !empty(PKG_OPTIONS:Mnls) && \
    !empty(USE_BUILTIN.gettext:M[yY][eE][sS]) && \
    !empty(TOOLS_PLATFORM.msgfmt:U)
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--without-libintl-prefix
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--disable-nls
.endif
