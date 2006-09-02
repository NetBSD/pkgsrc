# $NetBSD: Makefile,v 1.34 2006/09/02 18:17:40 rillig Exp $
#

DISTNAME=		qemu-0.8.1
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.qemu.org/
COMMENT=		CPU emulator using dynamic translation

CONFLICTS+=		qemu-bin-*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

GCC_REQD+=		3.0

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

# qemu cannot yet use gcc 4, see the faq/mailing lists
# (hint: use gcc_select on darwin/macos to choose gcc 3.3 instead)
.if !empty(CC_VERSION:Mgcc-4*)
PKG_FAIL_REASON+=	"${PKGNAME} cannot use "${CC_VERSION:Q}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/qemu
	${INSTALL_DATA} ${FILESDIR:Q}/Makefile.multinode-NetBSD \
		${PREFIX:Q}/share/doc/qemu/

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
