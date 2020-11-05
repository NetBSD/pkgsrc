# $NetBSD: Makefile,v 1.62 2020/11/05 09:08:59 ryoon Exp $

PKGREVISION= 4
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	atril-${VERSION}
CATEGORIES=	print

COMMENT=	Simple multi-page document viewer for the MATE environment

USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

PKGCONFIG_OVERRIDE+=	atril-document.pc.in
PKGCONFIG_OVERRIDE+=	atril-view.pc.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../print/web2c/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
