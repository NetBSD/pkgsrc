# $NetBSD: Makefile,v 1.18 2018/02/10 13:53:48 khorben Exp $
#

DISTNAME=	s10sh-0.2.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

MAINTAINER=	drochner@NetBSD.org
#HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh/
COMMENT=	USB/serial userspace driver for Canon PowerShot cameras

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s10sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/s10sh
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/s10sh

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
