# $NetBSD: Makefile,v 1.5 2002/10/26 14:27:22 drochner Exp $
#

DISTNAME=	s10sh-0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@netbsd.org
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
