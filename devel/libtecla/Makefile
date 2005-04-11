# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:28 tv Exp $

DISTNAME=	libtecla-1.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.astro.caltech.edu/~mcs/tecla/
COMMENT=	Interactive command line editing facilities

WRKSRC=			${WRKDIR}/${PKGBASE}
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
BUILD_TARGET=		default

.include "../../mk/bsd.prefs.mk"

# reentrant causes compilation problems
.if ${OPSYS} != "SunOS"
CONFIGURE_ENV+=		tecla_cv_reentrant=no
.endif

.include "../../mk/bsd.pkg.mk"
