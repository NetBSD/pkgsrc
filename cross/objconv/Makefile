# $NetBSD: Makefile,v 1.2 2016/05/08 07:28:14 ryoon Exp $

DISTNAME=	objconv
PKGNAME=	${DISTNAME}-2.39
CATEGORIES=	cross
MASTER_SITES=	http://www.agner.org/optimize/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.agner.org/optimize/
COMMENT=	Object file converter and disassembler
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_TOOLS+=	unzip:build

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin

post-extract:
	cd ${WRKSRC} && unzip source.zip

do-build:
	cd ${WRKSRC} && sh ./build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objconv \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
