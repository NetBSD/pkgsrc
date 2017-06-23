# $NetBSD: Makefile,v 1.6 2017/06/23 17:10:44 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	eom-${VERSION:R}.2
CATEGORIES=	graphics

COMMENT=	Eye of MATE: an image viewing and cataloging program

PKGCONFIG_OVERRIDE+=	data/eom.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
