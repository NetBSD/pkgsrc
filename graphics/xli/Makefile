# $NetBSD: Makefile,v 1.6 2001/05/22 09:32:23 wiz Exp $

DISTNAME=		xli-1.16nb1
CATEGORIES=		graphics x11
MASTER_SITES=		ftp://ftp.libpng.org/pub/png/src/ \
			${MASTER_SITE_XCONTRIB:=applications/}
DISTFILES=		xli.1.16.tar.gz \
			xli-png.tar.gz

MAINTAINER=		packages@netbsd.org
COMMENT=		Version of xloadimage, an X11 Image Loading Utility

DEPENDS+=		png>=1.0.11:../../graphics/png

NO_WRKSUBDIR=		yes

USE_IMAKE=		yes

pre-patch:
	@${PATCH} -d ${WRKSRC} -s -p1 < ${WRKSRC}/png.patch

.include "../../mk/bsd.pkg.mk"
