# New ports collection makefile for:    Mesa
# Version required:     2.2
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $NetBSD: Makefile,v 1.7 1998/02/02 08:10:51 hubertf Exp $
# FreeBSD Id: Makefile,v 1.19 1997/09/30 19:21:40 max Exp
#

DISTNAME=       MesaLib-2.4
PKGNAME=	Mesa-2.4
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://iris.ssec.wisc.edu/pub/Mesa/old-versions/
DISTFILES=	MesaLib-${SHLIB_VERSION}${EXTRACT_SUFX} \
		MesaDemos-${SHLIB_VERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=	netbsd
USE_X11=	yes
LIBS=		libMesaGL libMesaGLU libMesaaux libMesatk
SHLIB_VERSION=	2.4

do-install:
.for file in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}_pic.a ${PREFIX}/lib
	ranlib ${PREFIX}/lib/${file}_pic.a
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${SHLIB_VERSION} ${PREFIX}/lib
.endfor
.for file in GL GLU
	@ln -fs ${PREFIX}/lib/libMesa${file}_pic.a ${PREFIX}/lib/lib${file}_pic.a
	@ln -fs ${PREFIX}/lib/libMesa${file}.so.${SHLIB_VERSION} ${PREFIX}/lib/lib${file}.so.${SHLIB_VERSION}
.endfor
	@${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/* ${PREFIX}/include/GL
	@${MKDIR} ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/samples ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/demos ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/book ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/widgets-sgi ${PREFIX}/share/examples/Mesa
	${LDCONFIG} -m ${PREFIX}/lib || ${TRUE}

.include <bsd.port.mk>
