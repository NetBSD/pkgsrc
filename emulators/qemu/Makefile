# $NetBSD: Makefile,v 1.1.1.1 2004/11/09 13:05:33 xtraeme Exp $
#

DISTNAME=		qemu-0.6.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://fabrice.bellard.free.fr/qemu/
COMMENT=		CPU emulator using dynamic translation

ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*
CONFLICTS+=		qemu-bin-*

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
