# $NetBSD: Makefile,v 1.2 2002/03/21 10:42:38 tron Exp $

DISTNAME=	ffmpeg-0.4.5
CATEGORIES=	graphics net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

HAS_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS=	--cc=${CC} --disable-grab --disable-mmx --prefix=${PREFIX}
WRKSRC=		${WRKDIR}/ffmpeg

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/* \
	  ${PREFIX}/share/doc/ffmpeg

.include "../../mk/bsd.pkg.mk"
