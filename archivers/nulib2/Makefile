# $NetBSD: Makefile,v 1.20 2011/11/26 04:39:19 sbd Exp $
#

DISTNAME=	nulibdist-203
PKGNAME=	nulib2-2.0.3
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.nulib.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nulib.com/
COMMENT=	Handles Apple II ShrinkIt (NuFX) file/disk archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}
CONFIGURE_DIRS=		${WRKDIR}/${DISTNAME:S/dist/2/}
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=--cache-file=${WRKDIR}/config.cache

CFLAGS+=	-D__unix__

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
