# New packages collection makefile for:	Mesa
# Version required:     		2.6
#
# $NetBSD: Makefile,v 1.13 1998/03/26 22:54:40 frueauf Exp $
#

DISTNAME=       MesaLib-2.6
PKGNAME=	Mesa-2.6
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/Mesa/ \
		ftp://iris.ssec.wisc.edu/pub/Mesa/old-versions/
DISTFILES=	MesaLib-${MESA_VERSION}${EXTRACT_SUFX} \
		MesaDemos-${MESA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	mycroft@NetBSD.ORG

WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=	netbsd
USE_X11=	yes
MESA_LIBS=	libMesaGL libMesaGLU libMesaaux libMesatk
MESA_VERSION=	2.6
GLUT_LIBS=	libglut
GLUT_VERSION=	3.6

post-extract:
	@chmod +r ${WRKSRC}/demos/*

do-install:
.for file in ${MESA_LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.a ${PREFIX}/lib
	ranlib ${PREFIX}/lib/${file}.a
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${MESA_VERSION} ${PREFIX}/lib
.endfor
.for file in ${GLUT_LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.a ${PREFIX}/lib
	ranlib ${PREFIX}/lib/${file}.a
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${GLUT_VERSION} ${PREFIX}/lib
.endfor
.for file in GL GLU
	@ln -fs ${PREFIX}/lib/libMesa${file}.a ${PREFIX}/lib/lib${file}.a
	@ln -fs ${PREFIX}/lib/libMesa${file}.so.${MESA_VERSION} ${PREFIX}/lib/lib${file}.so.${MESA_VERSION}
.endfor
	@${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/* ${PREFIX}/include/GL
	@${MKDIR} ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/samples ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/demos ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/book ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/widgets-sgi ${PREFIX}/share/examples/Mesa
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/Mesa
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
