# $NetBSD: Makefile,v 1.8 2005/02/21 14:20:17 wiz Exp $
#

DISTNAME=	libtecla-1.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.astro.caltech.edu/~mcs/tecla/
COMMENT=	Interactive command line editing facilities

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
BUILD_TARGET=	default

BUILDLINK_TRANSFORM+=	rm:-D_POSIX_C_SOURCE=199506L

.include "../../mk/bsd.pkg.mk"
