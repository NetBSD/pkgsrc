# $NetBSD: Makefile,v 1.11 2004/09/28 22:05:57 tv Exp $
#

DISTNAME=	nulibdist-200
PKGNAME=	nulib2-2.0.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@duh.org
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
