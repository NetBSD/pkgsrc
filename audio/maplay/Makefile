# $NetBSD: Makefile,v 1.28 2025/04/21 16:21:40 wiz Exp $

DISTNAME=	maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
#MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

pre-configure:
	cd ${WRKSRC} && ${MAKE} pre-install

.include "../../mk/bsd.pkg.mk"
