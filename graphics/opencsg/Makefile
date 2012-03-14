# $NetBSD: Makefile,v 1.3 2012/03/14 23:11:58 joerg Exp $
#

PKGNAME=	opencsg-1.3.2
DISTNAME=	OpenCSG-1.3.2
PKG_REVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.opencsg.org/

MAINTAINER=	reinoud@tomaatnet.nl
HOMEPAGE=	http://www.opencsg.org/
COMMENT=	Image based CSG rendering library using OpenGL
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PREFIX}/include/

.include "../../mk/x11.buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
