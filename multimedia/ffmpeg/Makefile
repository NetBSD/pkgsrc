# $NetBSD: Makefile,v 1.35.6.1 2008/09/04 21:01:44 tron Exp $

DISTNAME=	ffmpeg-0.4.9-pre1
PKGNAME=	ffmpeg-0.4.9pre1
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ffmpeg/}

MAINTAINER=	zul@NetBSD-fr.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	MPEG decoding, encoding and streaming software

# The `sparc' code in libavcode/sparc is only suitable for sparc64
NOT_FOR_PLATFORM=	*-*-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
USE_TOOLS+=	gmake texi2html pod2man
USE_LIBTOOL=	YES

CONFLICTS+=	ffmpeg-devel-[0-9]*

REPLACE_PERL+=	doc/texi2pod.pl

CONF_FILES=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

MAKE_ENV+=	EXTRA_LIBS=${LIBGETOPT:Q} \
		FFSERVER_CONF=${PKG_SYSCONFDIR}/ffserver.conf \
		LOCALBASE=${LOCALBASE:Q}

CONFIGURE_ARGS+=	--cc=${CC:Q} --prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pp --disable-vhook --disable-debug
CONFIGURE_ARGS+=	--enable-gpl
CONFIGURE_ARGS+=	--enable-ffplay

INSTALLATION_DIRS=	include/ffmpeg/libpostproc lib \
			share/examples/ffmpeg share/doc/ffmpeg

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/libavcodec/apiexample.c \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/TODO \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/libavcodec/libpostproc/postprocess.h \
		${DESTDIR}${PREFIX}/include/ffmpeg/libpostproc

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
