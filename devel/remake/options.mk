# $NetBSD: options.mk,v 1.3 2024/03/25 15:16:32 nikita Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.remake
PKG_SUPPORTED_OPTIONS=	nls readline
PKG_SUGGESTED_OPTIONS=	nls readline

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

# Build NLS support only if a native implementation of gettext is available
# to avoid a circular dependency (gmake->gettext-tools->ncurses->gmake).
.include "../../devel/gettext-lib/builtin.mk"
.if !empty(PKG_OPTIONS:Mnls) && \
	${USE_BUILTIN.gettext:tl} == yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--without-libintl-prefix
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--disable-nls
.endif

# readline
.if !empty(PKG_OPTIONS:Mreadline)
.include "../../mk/readline.buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-readline
.endif
