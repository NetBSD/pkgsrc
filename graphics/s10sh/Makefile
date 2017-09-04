# $NetBSD: Makefile,v 1.15 2017/09/04 18:00:56 wiz Exp $
#

DISTNAME=	s10sh-0.2.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@NetBSD.org
#HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh/
COMMENT=	USB/serial userspace driver for Canon PowerShot cameras

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s10sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/s10sh
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/s10sh

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
