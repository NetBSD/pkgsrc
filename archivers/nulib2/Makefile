# $NetBSD: Makefile,v 1.7 2004/01/20 12:07:06 agc Exp $
#

DISTNAME=	nulibdist
PKGNAME=	nulib2-2.0.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@poxbox.com
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

WRKSRC=		${WRKDIR}/nulib2-200
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--cache-file=${WRKDIR}/config.cache

DIST_SUBDIR=	${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"

# nulib2 needs this to identify a Unixlike system
CFLAGS+=	-D__unix__
