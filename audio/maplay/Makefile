# $NetBSD: Makefile,v 1.25 2012/10/02 23:47:57 asau Exp $

DISTNAME=	maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c++
NOT_FOR_PLATFORM=	Interix-*-*

INSTALLATION_DIRS=	bin

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

pre-configure:
	cd ${WRKSRC} && ${MAKE} pre-install

.include "../../mk/bsd.pkg.mk"
