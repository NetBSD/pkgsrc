# $NetBSD: Makefile,v 1.12 2004/11/29 04:50:34 tv Exp $
#

DISTNAME=	nulibdist-203
PKGNAME=	nulib2-2.0.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:S/dist/2/}
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--cache-file=${WRKDIR}/config.cache

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-D__unix__

.include "../../mk/bsd.pkg.mk"
