# $NetBSD: Makefile,v 1.4 2002/08/25 21:49:17 jlam Exp $
#

DISTNAME=	nulibdist
PKGNAME=	nulib2-1.0.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@poxbox.com
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

WRKSRC=		${WRKDIR}/nulib2-101

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--cache-file=${WRKDIR}/config.cache

.include "../../mk/bsd.pkg.mk"

# nulib2 needs this to identify a Unixlike system
CFLAGS+=	-D__unix__
