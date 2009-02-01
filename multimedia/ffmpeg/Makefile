# $NetBSD: Makefile,v 1.46.2.1 2009/02/01 03:50:57 rtr Exp $

DISTNAME=	ffmpeg-${DISTVERSION}
PKGNAME=	ffmpeg-${DISTVERSION:S/-//g}
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	MPEG decoding, encoding and streaming software

DISTVERSION=	2008-07-27
PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake texi2html pod2man

REPLACE_PERL+=	doc/texi2pod.pl

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	ffserver.c
SUBST_SED.conf=		-e 's,/etc/ffserver.conf,${PKG_SYSCONFDIR}/ffserver.conf,g'
SUBST_MESSAGE.conf=	Fixing configuration path.

CONFLICTS+=	ffmpeg-devel-[0-9]*

PLIST_SRC+=	${PKGDIR}/PLIST

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

MAKE_ENV+=	EXTRA_LIBS=${LIBGETOPT:Q}
# LOCALBASE=${LOCALBASE:Q}

# Let's not put garbage into /tmp
CONFIGURE_ENV+=		TMPDIR=${WRKDIR:Q}

CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR} \
			--cc=${CC:Q} \
			--prefix=${PREFIX:Q} \
			--disable-debug \
			--disable-vhook \
			--enable-avfilter \
			--enable-gpl \
			--enable-postproc \
			--enable-pthreads \
			--enable-shared \
			--enable-swscale \
			--enable-libvorbis \
			--enable-libmp3lame \
			--disable-stripping

# causes complaining about being miscompiled
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--disable-mmx \
			--disable-mmx2 \
			--disable-ssse3
.endif

INSTALLATION_DIRS=	lib share/examples/ffmpeg share/doc/ffmpeg

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/libavcodec/apiexample.c \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/TODO \
		${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/ffmpeg
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${DESTDIR}${PREFIX}/share/examples/ffmpeg

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
