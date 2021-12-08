# $NetBSD: Makefile,v 1.11 2021/12/08 16:05:03 adam Exp $

DISTNAME=	OpenCSG-1.3.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.opencsg.org/

MAINTAINER=	reinoud@tomaatnet.nl
HOMEPAGE=	http://www.opencsg.org/
COMMENT=	Image based CSG rendering library using OpenGL
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
BUILD_DIRS=		src

INSTALLATION_DIRS=	include lib

LDFLAGS.Darwin+=	-framework OpenGL
LDFLAGS.*+=		-lGL -lGLU -lXmu

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PREFIX}/include/
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/src/libopencsg.la ${DESTDIR}${PREFIX}/lib

.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
