# $NetBSD: options.mk,v 1.4 2019/10/20 16:29:42 triaxx Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmake
PKG_SUPPORTED_OPTIONS=	nls

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.include "../../devel/gettext-lib/builtin.mk"
.if !empty(PKG_OPTIONS:Mnls) && \
    !empty(IS_BUILTIN.gettext:M[yY][eE][sS])
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
PREFER.gettext=		native
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--without-libintl-prefix
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--disable-nls
.endif
