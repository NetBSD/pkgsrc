# $NetBSD: Makefile,v 1.6 1998/06/04 07:20:44 hubertf Exp $

DISTNAME=	wine980215
PKGNAME=	wine-980215
CATEGORIES=	emulators
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/
DISTFILES=	Wine-980215.tar.gz
ONLY_FOR_ARCHS=	i386

MAINTAINER=	mycroft@NetBSD.ORG

DEPENDS+=       xpm-3.4j:../../graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dll
USE_GMAKE=	yes

MAN1=		wine.1

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
