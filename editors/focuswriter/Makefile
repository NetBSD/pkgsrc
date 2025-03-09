# $NetBSD: Makefile,v 1.45 2025/03/09 20:56:44 pin Exp $

DISTNAME=	focuswriter-1.8.11
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=gottcode/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gottcode.org/focuswriter/
COMMENT=	Simple, distraction-free writing environment
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PKGMANDIR}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_DATADIR=${PREFIX}/share

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
