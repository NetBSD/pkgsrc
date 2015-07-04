# $NetBSD: Makefile,v 1.25 2015/07/04 16:18:36 joerg Exp $

DISTNAME=	mpeg2vidcodec_v12
PKGNAME=	mpeg2codec-1.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mpeg.org/pub/mpeg/mssg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mpeg.org/MSSG/
COMMENT=	MPEG Software Simulation Group's MPEG-2 Encoder and Decoder

WRKSRC=		${WRKDIR}/mpeg2

INSTALLATION_DIRS=	bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} \
	  ${WRKSRC}/src/mpeg2dec/mpeg2decode \
	  ${WRKSRC}/src/mpeg2enc/mpeg2encode \
	  ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mpeg2codec
	${INSTALL_DATA} ${WRKSRC}/doc/mpeg2enc.doc \
	  ${DESTDIR}${PREFIX}/share/doc/mpeg2codec
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mpeg2codec
	${INSTALL_DATA} ${WRKSRC}/par/* ${DESTDIR}${PREFIX}/share/mpeg2codec

.include "../../mk/bsd.pkg.mk"
