# $NetBSD: Makefile,v 1.22 2005/12/11 09:40:39 wiz Exp $
#

DISTNAME=		qemu-0.7.2
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

CONFLICTS+=		qemu-bin-*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

GCC_REQD+=		3.0

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	"Fixing hardcoded audio device."

# Remove -march/-mcpu from CFLAGS, otherwise it will fail
# to build in the SSE code.
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu

.include "../../mk/compiler.mk"

# qemu cannot yet use gcc 4, see the faq/mailing lists
# (hint: use gcc_select on darwin/macos to choose gcc 3.3 instead)
.if !empty(CC_VERSION:Mgcc-4*)
PKG_FAIL_REASON+=	"${PKGNAME} cannot use ${CC_VERSION}"
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${PREFIX}/share/doc/qemu

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
