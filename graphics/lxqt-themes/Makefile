# $NetBSD: Makefile,v 1.1 2020/04/25 00:56:46 gutteridge Exp $

DISTNAME=	lxqt-themes-0.14.0
CATEGORIES=	graphics
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-themes/0.14.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Themes, graphics and icons for LXQt
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
