# $NetBSD: Makefile,v 1.11 1998/07/15 12:14:24 agc Exp $

DISTNAME=		Wine-980614
PKGNAME=		wine-980614
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
ONLY_FOR_ARCHS=		i386

MAINTAINER=	mycroft@NetBSD.ORG

CONFLICTS=	wine-980215

DEPENDS+=       xpm-3.4k:../../graphics/xpm

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-dll
WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.pkg.mk"
