# $NetBSD: Makefile,v 1.1 2022/12/10 12:50:58 wiz Exp $

DISTNAME=	d11amp_0.59
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	audio
MASTER_SITES=	https://www.dettus.net/d11amp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dettus@dettus.net
HOMEPAGE=	https://www.dettus.net/d11amp/
COMMENT=	Simple MP3 player
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	bin  ${PKGMANDIR}/man1

USE_TOOLS+=	pkg-config


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/d11amp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/d11amp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

## The idea of this test is to check if the output is the expected one.
## for this, the sha256sum is being compared.
do-test:
	cd ${WRKSRC} && ${MAKE} SHA256_CMD=sha256 TMP_DIR=/tmp/d11amp check

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
