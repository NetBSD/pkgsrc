# $NetBSD: Makefile,v 1.4 2004/01/23 23:59:54 kristerw Exp $
#

DISTNAME=	libtecla-1.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.astro.caltech.edu/~mcs/tecla/
COMMENT=	Interactive command line editing facilities

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
ALL_TARGET=	default

.include "../../mk/bsd.pkg.mk"
