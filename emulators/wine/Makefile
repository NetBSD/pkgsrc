# $NetBSD: Makefile,v 1.7 1998/06/18 23:48:52 tron Exp $

DISTNAME=		Wine-980614
PKGNAME=		wine-980614
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
ONLY_FOR_ARCHS=		i386

MAINTAINER=	mycroft@NetBSD.ORG

DEPENDS+=       xpm-3.4j:../../graphics/xpm

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-dll
#USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	${LDCONFIG} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.pkg.mk"
