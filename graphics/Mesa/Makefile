# $NetBSD: Makefile,v 1.18 1998/09/05 19:26:02 tron Exp $
#

DISTNAME=       MesaLib-2.6
PKGNAME=	Mesa-2.6
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/Mesa/ \
		ftp://iris.ssec.wisc.edu/pub/Mesa/old-versions/
DISTFILES=	MesaLib-${MESA_VERSION}${EXTRACT_SUFX} \
		MesaDemos-${MESA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.ssec.wisc.edu/~brianp/Mesa.html

WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=	netbsd
USE_X11=	yes
MESA_LIBS=	libMesaGL libMesaGLU libMesaaux libMesatk
MESA_VERSION=	2.6
GLUT_LIBS=	libglut
GLUT_VERSION=	3.6

post-extract:
	@chmod +r ${WRKSRC}/demos/*
	@find ${WRKSRC} -type f -name "*~" | xargs ${RM} -f

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
	${LN} -f ${PREFIX}/lib/libMesaGL.so.2.6 ${PREFIX}/lib/libGL.so.2.6
	${LN} -f ${PREFIX}/lib/libMesaGLU.so.2.6 ${PREFIX}/lib/libGLU.so.2.6
	${LN} -f ${PREFIX}/lib/libMesaGL.a ${PREFIX}/lib/libGL.a
	${LN} -f ${PREFIX}/lib/libMesaGLU.a ${PREFIX}/lib/libGLU.a

.include "../../mk/bsd.pkg.mk"
