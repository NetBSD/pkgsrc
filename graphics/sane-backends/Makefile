# $NetBSD: Makefile,v 1.11 2002/09/22 22:01:12 wiz Exp $

.include "Makefile.common"

DISTNAME=       sane-backends-${SANE_VERSION}

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

.include "../../devel/libusb/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# -O to work around a bug with -O2 and egcs.
CFLAGS+=	-O
