# $NetBSD: Makefile,v 1.3 2000/04/22 17:03:35 kim Exp $

DISTNAME=		xli-1.16nb1
CATEGORIES=		graphics x11
MASTER_SITES=		ftp://ftp.libpng.org/pub/png/src/ \
			${MASTER_SITE_XCONTRIB:=applications/}
DISTFILES=		xli.1.16.tar.gz \
			xli-png.tar.gz

MAINTAINER=		packages@netbsd.org

DEPENDS+=		png>=1.0.3:../../graphics/png

NO_WRKSUBDIR=		yes

USE_IMAKE=		yes

pre-patch:
	@${PATCH} -d ${WRKSRC} -s -p1 < ${WRKSRC}/png.patch

.include "../../mk/bsd.pkg.mk"
