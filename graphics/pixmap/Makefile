# $NetBSD: Makefile,v 1.16 2002/04/17 02:52:48 jlam Exp $
# FreeBSD: Makefile,v 1.8 1996/11/18 09:53:36 asami Exp
#

DISTNAME=		pixmap2.6
PKGNAME=		pixmap-2.6.4
PKGREVISION=		1
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

WRKSRC=			${WRKDIR}/pixmap

MAKE_ENV+=		LOCAL_LDFLAGS="${LDFLAGS}"
MAKE_ENV+=		MOTIFBASE="${MOTIFBASE}"

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
