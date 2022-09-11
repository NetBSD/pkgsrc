# $NetBSD: Makefile,v 1.10 2022/09/11 12:51:35 wiz Exp $

VERSION=		1.70
DISTNAME=		xm8_${VERSION:S/.//}
PKGNAME=		xm8-${VERSION}
PKGREVISION=		8
#PKGREVISION=		
CATEGORIES=		emulators
MASTER_SITES=		http://retropc.net/pi/
EXTRACT_SUFX=		.zip

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://retropc.net/pi/
COMMENT=		Multi-platform NEC PC-8801 emulator
LICENSE=		gnu-gpl-v2

EXTRACT_DIR=		${WRKDIR}/${DISTNAME}
WRKSRC=			${EXTRACT_DIR}

USE_TOOLS+=		gmake unzip
USE_LANGUAGES=		c c++03
NO_CONFIGURE=		YES

BUILD_DIRS=		Source/Linux
MAKE_FILE=		makefile

INSTALLATION_DIRS+=	bin share/doc/xm8

post-extract:
	(cd ${WRKSRC}/Source && ${UNZIP_CMD} Source.zip)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Source/Linux/xm8 \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README-XM8.txt \
	    ${DESTDIR}${PREFIX}/share/doc/xm8

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
