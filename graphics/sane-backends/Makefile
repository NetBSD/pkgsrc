# $NetBSD: Makefile,v 1.10 2002/02/10 00:50:41 rh Exp $

.include "Makefile.common"

DISTNAME=       sane-backends-${SANE_VERSION}

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libusb/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# -O to work around a bug with -O2 and egcs.
CFLAGS+=	-O
