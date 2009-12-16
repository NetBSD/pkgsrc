# $NetBSD: options.mk,v 1.3 2009/12/16 22:52:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gwaei
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
GCONF_SCHEMAS=		gwaei.schemas
PLIST_SRC+=		PLIST.gnome

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/schemas/gwaei.schemas \
		${DESTDIR}${PREFIX}/share/gconf/schemas/

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.22.0
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.22.0
.include "../../devel/libgnome/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsexy+=		libsexy>=0.1.11
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.else
CONFIGURE_ARGS+=	--without-gnome
.endif
