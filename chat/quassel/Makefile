# $NetBSD: Makefile,v 1.57 2026/09/29 06:04:06 wiz Exp $

.include "Makefile.common"
PKGREVISION=	32
COMMENT=	Modern, cross-platform, distributed IRC client

USE_TOOLS+=	bash perl

REPLACE_BASH+=	po/update.sh
REPLACE_BASH+=	scripts/tx-sync.sh
REPLACE_PERL+=	data/scripts/inxi
REPLACE_PERL+=	data/scripts/mpris

CMAKE_CONFIGURE_ARGS+=	-DWANT_CORE=OFF

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../textproc/sonnet/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
