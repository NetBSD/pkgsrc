# $NetBSD: Makefile,v 1.56 2009/05/13 19:02:18 kefren Exp $
#

DISTNAME=		qemu-0.9.1
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://bellard.org/qemu/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bellard.org/qemu/
COMMENT=		CPU emulator using dynamic translation

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		qemu-bin-[0-9]*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake perl:build
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

# Workaround for PR/41007 - ensure WRKSRC comes before any buildlinked
# directories so we pickup our audio/audio.h. Cannot use CPPFLAGS for this
CFLAGS+=	-I${WRKSRC}

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=		3.0

.if !empty(MACHINE_PLATFORM:MNetBSD-[4-9]*)
USE_PKGSRC_GCC=	yes
.endif

CONFIGURE_ENV+=		PKGMANDIR=${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX:Q}/share/qemu

.if !empty(MACHINE_PLATFORM:MNetBSD-*)
SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	pre-configure
SUBST_FILES.lib=	x86_64.ld
SUBST_SED.lib=		-e s,/lib64,/lib,g
SUBST_MESSAGE.lib=	fixing hardcoded paths to libraries.
.endif

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	pre-configure
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e s,/dev/dsp,${DEVOSSAUDIO:Q},g
SUBST_MESSAGE.snd=	Fixing hardcoded audio device.

SUBST_CLASSES+=		smbd
SUBST_STAGE.smbd=	pre-configure
SUBST_FILES.smbd=	vl.c
SUBST_SED.smbd=		-e s,/usr/sbin/smbd,${PREFIX:Q}/sbin/smbd,g
SUBST_MESSAGE.smbd=	Fixing hardcoded paths.

REPLACE_PERL+=		texi2pod.pl

# Remove -march/-mcpu from CFLAGS, otherwise it will fail
# to build in the SSE code.
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu rm:-msse rm:-msse2

BUILDLINK_PASSTHRU_DIRS+= /usr/lib
BUILDLINK_PASSTHRU_RPATHDIRS+= /usr/lib

# Does not build with the stack protector
.if ${OPSYS} == "DragonFly"
CFLAGS+=		-fno-stack-protector
.endif

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
CONFIGURE_ARGS+=	--disable-gcc-check
.endif


INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/qemu

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${DESTDIR}${PREFIX}/share/doc/qemu/
	${INSTALL_MAN} ${WRKSRC}/qemu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/qemu-img.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
