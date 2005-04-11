# $NetBSD: Makefile,v 1.13 2005/04/11 21:44:49 tv Exp $
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
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--cache-file=${WRKDIR}/config.cache

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-D__unix__

.include "../../mk/bsd.pkg.mk"
