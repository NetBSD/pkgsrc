# $NetBSD: Makefile,v 1.4 2002/10/08 20:08:50 wiz Exp $
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
	${INSTALL} ${WRKSRC}/s10sh ${PREFIX}/bin

.include "../../devel/libusb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
