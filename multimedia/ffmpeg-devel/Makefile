# $NetBSD: Makefile,v 1.7 2008/04/20 20:38:53 heinz Exp $

DISTNAME=	ffmpeg-${DISTVERSION}
PKGNAME=	ffmpeg-devel-${DISTVERSION:S/-//g}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ffmpeg.mplayerhq.hu/
COMMENT=	MPEG decoding, encoding and streaming software

DISTVERSION=	2007-10-04
PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake texi2html pod2man

REPLACE_PERL+=	doc/texi2pod.pl

SUBST_CLASSES+=		conf pc
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	ffserver.c
SUBST_SED.conf=		-e 's,/etc/ffserver.conf,${PKG_SYSCONFDIR}/ffserver.conf,g'
SUBST_MESSAGE.conf=	Fixing configuration path.
SUBST_STAGE.pc=		pre-install
SUBST_FILES.pc=		*.pc
SUBST_SED.pc=		-e 's|-lx264||g'
SUBST_MESSAGE.pc=	Fixing hardcoded libs.

PLIST_SRC+=	${PKGDIR}/PLIST

CONF_FILES+=	${PREFIX}/share/examples/ffmpeg/ffserver.conf \
		${PKG_SYSCONFDIR}/ffserver.conf

MAKE_ENV+=	EXTRA_LIBS=${LIBGETOPT:Q} \
		LOCALBASE=${LOCALBASE:Q}

CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR} \
			--cc=${CC:Q} \
			--prefix=${PREFIX:Q} \
			--disable-vhook \
			--disable-debug \
			--enable-pp \
			--enable-gpl \
			--enable-memalign-hack \
			--enable-pthreads \
			--enable-shared


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

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
