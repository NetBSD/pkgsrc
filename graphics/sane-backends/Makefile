# $NetBSD: Makefile,v 1.12 2002/11/09 13:45:58 wiz Exp $

.include "Makefile.common"
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

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
