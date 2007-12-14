PKG_OPTIONS_VAR=	PKG_OPTIONS.tre
PKG_SUPPORTED_OPTIONS=	nls

CHECK_BUILTIN.gettext:=	yes
.include "../../devel/gettext-lib/builtin.mk"
CHECK_BUILTIN.gettext:=	no

.if !empty(USE_BUILTIN.gettext:tl:Myes)
PKG_SUGGESTED_OPTIONS=	nls
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
PLIST_SRC+=		PLIST.nls
USE_PKGLOCALEDIR=	yes
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
