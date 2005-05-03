# $NetBSD: Makefile,v 1.10 2005/05/03 11:18:47 xtraeme Exp $
#

DISTNAME=		qemu-0.7.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		dhowlland@users.sourceforge.net
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

CONFLICTS+=		qemu-bin-*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_GNU_TOOLS+=		make
USE_X11=		yes
HAS_CONFIGURE=		yes

GCC_REQD+=		3.0

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	"Fixing hardcoded audio device."

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
