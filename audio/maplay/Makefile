# $NetBSD: Makefile,v 1.16 2005/03/24 21:12:50 wiz Exp $

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

WRKSRC=		${WRKDIR}

pre-configure:
	@(cd ${WRKSRC}; ${MAKE} pre-install)

.include "../../mk/bsd.pkg.mk"
