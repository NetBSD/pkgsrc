# $NetBSD: Makefile,v 1.11 2016/02/25 10:15:46 jperkin Exp $

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

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_MESSAGE.pthread=	Fixing -lpthread references.
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's/-D_REENTRANT/${PTHREAD_CFLAGS}/g'
SUBST_SED.pthread+=	-e 's/-lpthread/${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}/g'

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Fixing pkgconfig directory
SUBST_FILES.pc=		Makefile.in
SUBST_SED.pc=		-e 's/$$(libdir)\/pkgconfig/$$(prefix)\/lib\/pkgconfig/g'

CFLAGS.Darwin+=		-Wno-deprecated-declarations

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
