# $NetBSD: Makefile,v 1.10 2004/07/28 02:47:35 minskim Exp $
#

DISTNAME=	nulibdist-200
PKGNAME=	nulib2-2.0.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@poxbox.com
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/nulib2-200
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--cache-file=${WRKDIR}/config.cache

.include "../../mk/bsd.pkg.mk"

# nulib2 needs this to identify a Unixlike system
CFLAGS+=	-D__unix__
