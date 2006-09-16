# $NetBSD: Makefile,v 1.40 2006/09/16 12:09:09 hira Exp $
#

DISTNAME=		qemu-0.8.2
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.qemu.org/
COMMENT=		CPU emulator using dynamic translation

CONFLICTS+=		qemu-bin-*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=		3.0

.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
USE_PKGSRC_GCC= 	yes
.endif

CONFIGURE_ENV+=		PKGMANDIR=${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX:Q}/share/qemu

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e s,/dev/dsp,${DEVOSSAUDIO:Q},g
SUBST_MESSAGE.snd=	Fixing hardcoded audio device.

SUBST_CLASSES+=		smbd
SUBST_STAGE.smbd=	post-patch
SUBST_FILES.smbd=	vl.c
SUBST_SED.smbd=		-e s,/usr/sbin/smbd,${PREFIX:Q}/sbin/smbd,g
SUBST_MESSAGE.smbd=	Fixing hardcoded paths.

# Remove -march/-mcpu from CFLAGS, otherwise it will fail
# to build in the SSE code.
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
CONFIGURE_ARGS+=	--disable-gcc-check
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/qemu
	${INSTALL_DATA} ${FILESDIR:Q}/Makefile.multinode-NetBSD \
		${PREFIX:Q}/share/doc/qemu/

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
