# $NetBSD: Makefile,v 1.3 2000/12/12 17:22:40 drochner Exp $
#

DISTNAME=		Mesa-3.4
PKGNAME=		${DISTNAME:S/Mesa/glut/}
CATEGORIES=		graphics
MASTER_SITES= 		ftp://ftp.mesa3d.org/mesa/ \
			${MASTER_SITE_SOURCEFORGE:=mesa3d/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES+=		${DISTNAME:S/Mesa/MesaLib/}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/Mesa/MesaDemos/}${EXTRACT_SUFX}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ssec.wisc.edu/~brianp/Mesa.html

CONFLICTS+=		Mesa-glx-*
CONFLICTS+=		Mesa<3.2.1

USE_X11BASE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-static

do-build:
	cd ${WRKSRC}/src-glut && ${MAKE}

do-install:
	cd ${WRKSRC}/src-glut && ${MAKE} install

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
.for inc in glut.h glutf90.h
	${INSTALL_DATA} ${WRKSRC}/include/GL/${inc} ${PREFIX}/include/GL
.endfor

.include "../../mk/bsd.pkg.mk"
