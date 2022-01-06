# $NetBSD: Makefile,v 1.15 2022/01/06 07:53:46 pin Exp $

VERSION=	0.10.0
DISTNAME=	FeatherNotes-V${VERSION}
PKGNAME=	feathernotes-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/FeatherNotes/
COMMENT=	Lightweight Qt5 hierarchical notes-manager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FeatherNotes-${VERSION}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
