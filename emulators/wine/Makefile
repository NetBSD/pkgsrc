# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:24 agc Exp $

DISTNAME=	wine980215
PKGNAME=	wine-980215
CATEGORIES=	emulators
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/
DISTFILES=	Wine-980215.tar.gz
ONLY_FOR_ARCHS=	i386

MAINTAINER=	mycroft@NetBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dll
USE_GMAKE=	yes

MAN1=		wine.1

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
