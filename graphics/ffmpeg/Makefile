# $NetBSD: Makefile,v 1.3 2002/03/22 11:59:18 tron Exp $

DISTNAME=	ffmpeg-0.4.5
PKGREVISION=	1
CATEGORIES=	graphics net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://ffmpeg.sourceforge.net/
COMMENT=	MPEG decoding, encoding and streaming software

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

HAS_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
MAKE_ENV+=	EXTRA_LIBS="${LIBGETOPT}" \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE="${LOCALBASE}"

CONFIGURE_ARGS=	--cc=${CC} --disable-grab --disable-mmx --prefix=${PREFIX}
WRKSRC=		${WRKDIR}/ffmpeg

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ffmpeg \
	  ${PREFIX}/share/examples/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/* \
	  ${PREFIX}/share/doc/ffmpeg
	${MV} ${PREFIX}/share/doc/ffmpeg/ffserver.conf \
	  ${PREFIX}/share/examples/ffmpeg

.include "../../devel/libgetopt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
