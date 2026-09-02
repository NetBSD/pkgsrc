# $NetBSD: Makefile,v 1.116 2026/09/02 19:01:51 wiz Exp $

DISTNAME=	texstudio-4.9.5
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=texstudio-org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://texstudio.org/
COMMENT=	Integrated writing environment for creating LaTeX documents
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c

.include "../../devel/cmake/build.mk"

.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-qt6/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
