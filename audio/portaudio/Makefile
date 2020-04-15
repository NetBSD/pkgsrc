# $NetBSD: Makefile,v 1.29 2020/04/15 17:12:14 nia Exp $

DISTNAME=	pa_stable_v190600_20161030
PKGNAME=	${DISTNAME:S/^pa_stable_v/portaudio-/1:S/_/./g}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform audio API
LICENSE=	mit

CONFLICTS+=	portaudio-devel-[0-9]*
SUPERSEDES+=	portaudio-devel-[0-9]*

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

# No rule to make target '../../../lib/libportaudio.la', needed by 'libportaudiocpp.la'.  Stop.
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE_LIBSUBDIR=	portaudio2

NOT_FOR_PLATFORM=	Interix-*-*

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/portaudio2
CONFIGURE_ARGS+=	--disable-mac-universal

.include "../../mk/oss.buildlink3.mk"
PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
PLIST.oss=		yes
LDFLAGS+=		${LIBOSSAUDIO}
.endif

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
SUBST_FILES.pc=		Makefile.in bindings/cpp/Makefile.in
SUBST_SED.pc=		-e 's/$$(libdir)\/pkgconfig/$$(prefix)\/lib\/pkgconfig/g'

CFLAGS.Darwin+=		-Wno-deprecated-declarations

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
