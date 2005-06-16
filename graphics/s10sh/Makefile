# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:59 jlam Exp $
#

DISTNAME=	s10sh-0.2.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh
COMMENT=	USB/serial userspace driver for Canon PowerShot cameras

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s10sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/s10sh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/s10sh

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
