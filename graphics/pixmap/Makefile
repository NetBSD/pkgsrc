# $NetBSD: Makefile,v 1.14 2002/01/09 02:37:47 fredb Exp $
# FreeBSD: Makefile,v 1.8 1996/11/18 09:53:36 asami Exp
#

DISTNAME=		pixmap2.6
PKGNAME=		pixmap-2.6.4nb1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/pixmap/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		pixmap_2.6.patch1.gz \
			pixmap_2.6.patch2.gz \
			pixmap_2.6.patch3.gz \
			pixmap_2.6.patch4.gz

MAINTAINER=		packages@netbsd.org
COMMENT=		Pixmap editor based on XPM library

USE_IMAKE=		YES
USE_MOTIF=		YES

WRKSRC=			${WRKDIR}/pixmap

MAKE_ENV+=		LOCAL_LDFLAGS="${LDFLAGS}"
MAKE_ENV+=		MOTIFBASE="${MOTIFBASE}"

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
