# $NetBSD: Makefile,v 1.18 2006/03/04 21:28:57 jlam Exp $

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams

WRKSRC=		${WRKDIR}

NOT_FOR_PLATFORM=	Interix-*-*

pre-configure:
	cd ${WRKSRC} && ${MAKE} pre-install

.include "../../mk/bsd.pkg.mk"
