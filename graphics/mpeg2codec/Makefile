# $NetBSD: Makefile,v 1.1.1.1 1998/09/28 18:10:27 tron Exp $

DISTNAME=	mpeg2vidcodec_v12
PKGNAME=	mpeg2codec-1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mpeg.org/pub/mpeg/mssg/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.mpeg.org/MSSG/

USE_X11=	yes
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/mpeg2

do-install:
	${INSTALL_PROGRAM} \
	  ${WRKSRC}/src/mpeg2dec/mpeg2decode \
	  ${WRKSRC}/src/mpeg2enc/mpeg2encode \
	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/mpeg2codec
	${INSTALL_DATA} ${WRKSRC}/doc/mpeg2enc.doc \
	  ${PREFIX}/share/doc/mpeg2codec
	${MKDIR} ${PREFIX}/share/mpeg2codec
	${INSTALL_DATA} ${WRKSRC}/par/* ${PREFIX}/share/mpeg2codec

.include "../../mk/bsd.pkg.mk"
