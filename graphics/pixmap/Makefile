# $NetBSD: Makefile,v 1.23 2004/04/25 07:11:48 snj Exp $
# FreeBSD: Makefile,v 1.8 1996/11/18 09:53:36 asami Exp
#

DISTNAME=		pixmap2.6
PKGNAME=		pixmap-2.6.4
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/pixmap/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		pixmap_2.6.patch1.gz \
			pixmap_2.6.patch2.gz \
			pixmap_2.6.patch3.gz \
			pixmap_2.6.patch4.gz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Pixmap editor based on XPM library

WRKSRC=			${WRKDIR}/pixmap
USE_BUILDLINK3=		YES
USE_IMAKE=		YES

MAKE_ENV+=		LOCAL_LDFLAGS="${LDFLAGS}"
MAKE_ENV+=		MOTIFBASE="${MOTIFBASE}"

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
