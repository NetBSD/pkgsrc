# $NetBSD: Makefile,v 1.20 2007/02/22 19:30:03 wiz Exp $

DISTNAME=	maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c++
NOT_FOR_PLATFORM=	Interix-*-*

pre-configure:
	cd ${WRKSRC} && ${MAKE} pre-install

.include "../../mk/bsd.pkg.mk"
