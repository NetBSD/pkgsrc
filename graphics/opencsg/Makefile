# $NetBSD: Makefile,v 1.8 2016/02/25 13:37:48 jperkin Exp $

DISTNAME=	OpenCSG-1.3.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
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

.include "../../graphics/glut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
