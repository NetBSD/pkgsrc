# $NetBSD: Makefile,v 1.14 2004/04/25 04:45:36 minskim Exp $

DISTNAME=	mpeg2vidcodec_v12
PKGNAME=	mpeg2codec-1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mpeg.org/pub/mpeg/mssg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mpeg.org/MSSG/
COMMENT=	MPEG Software Simulation Group's MPEG-2 Encoder and Decoder

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/mpeg2
USE_BUILDLINK3=		yes
USE_X11BASE=		# defined

INSTALLATION_DIRS=	bin

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
