# $NetBSD: Makefile,v 1.31 2020/04/12 08:28:57 adam Exp $
#

DISTNAME=	release-0.12.0
PKGNAME=	${DISTNAME:C/release/speedcrunch/}
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://bitbucket.org/heldercorreia/speedcrunch/get/
DIST_SUBDIR=	speedcrunch

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.speedcrunch.org/
COMMENT=	Calculator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/heldercorreia-speedcrunch-ea93b21f9498/src
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS=	gmake # Required for handling file names with whitespaces

post-build:
	(cd ${WRKSRC} && ${QTDIR}/bin/lrelease speedcrunch.pro)

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
