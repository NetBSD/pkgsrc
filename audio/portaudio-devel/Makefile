# $NetBSD: Makefile,v 1.8 2014/07/21 07:15:07 dbj Exp $

DISTNAME=	pa_stable_v19_20140130
PKGNAME=	portaudio-devel-20140130
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API
LICENSE=	mit

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBSUBDIR=portaudio2
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/portaudio2
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--disable-mac-universal
LDFLAGS+=		${LIBOSSAUDIO}
PKGCONFIG_OVERRIDE=	portaudio-2.0.pc.in
WRKSRC=			${WRKDIR}/portaudio

INSTALLATION_DIRS=	include/portaudio2 lib/portaudio2 lib/pkgconfig

SUBST_CLASSES+=         pthread
SUBST_STAGE.pthread=    pre-configure
SUBST_MESSAGE.pthread=  Fixing -lpthread references.
SUBST_FILES.pthread=    configure
SUBST_SED.pthread=      -e 's/-D_REENTRANT/${PTHREAD_CFLAGS}/g'
SUBST_SED.pthread+=     -e 's/-lpthread/${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}/g'

SUBST_CLASSES+=         pkgconfig
SUBST_STAGE.pkgconfig=  pre-configure
SUBST_MESSAGE.pkgconfig=Fixing pkgconfig directory
SUBST_FILES.pkgconfig=  Makefile.in
SUBST_SED.pkgconfig=    -e 's/$$(libdir)\/pkgconfig/$$(prefix)\/lib\/pkgconfig/g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=		-Wno-deprecated-declarations
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
