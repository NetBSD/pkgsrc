# $NetBSD: Makefile,v 1.6 2003/07/17 21:42:43 grant Exp $
#

DISTNAME=	s10sh-0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh
COMMENT=	USB/serial userspace driver for Canon PowerShot cameras

USE_BUILDLINK2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s10sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/s10sh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/s10sh

.include "../../devel/libusb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
