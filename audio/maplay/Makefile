# $NetBSD: Makefile,v 1.23 2011/11/22 20:57:34 wiz Exp $

DISTNAME=	maplay1_2
PKGNAME=	maplay-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/maplay1.2/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG audio player/decoder for layer I and II MPEG audio streams
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c++
NOT_FOR_PLATFORM=	Interix-*-*

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && ${MAKE} pre-install

.include "../../mk/bsd.pkg.mk"
