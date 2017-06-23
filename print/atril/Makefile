# $NetBSD: Makefile,v 1.12 2017/06/23 17:05:52 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	atril-${VERSION}
CATEGORIES=	print

COMMENT=	Simple multi-page document viewer for the MATE environment

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	atril-document.pc.in
PKGCONFIG_OVERRIDE+=	atril-view.pc.in

CONFIGURE_ARGS+=	--disable-introspection

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
