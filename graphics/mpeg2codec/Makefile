# $NetBSD: Makefile,v 1.11 2004/01/20 12:18:16 agc Exp $

DISTNAME=	mpeg2vidcodec_v12
PKGNAME=	mpeg2codec-1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mpeg.org/pub/mpeg/mssg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mpeg.org/MSSG/
COMMENT=	MPEG Software Simulation Group's MPEG-2 Encoder and Decoder

WRKSRC=		${WRKDIR}/mpeg2
USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined

do-install:
	${INSTALL_PROGRAM} \
	  ${WRKSRC}/src/mpeg2dec/mpeg2decode \
	  ${WRKSRC}/src/mpeg2enc/mpeg2encode \
	  ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mpeg2codec
	${INSTALL_DATA} ${WRKSRC}/doc/mpeg2enc.doc \
	  ${PREFIX}/share/doc/mpeg2codec
	${INSTALL_DATA_DIR} ${PREFIX}/share/mpeg2codec
	${INSTALL_DATA} ${WRKSRC}/par/* ${PREFIX}/share/mpeg2codec

.include "../../mk/bsd.pkg.mk"
