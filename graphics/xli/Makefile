# $NetBSD: Makefile,v 1.12 2001/09/09 20:36:31 agc Exp $

DISTNAME=	xli-1.16nb1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		${MASTER_SITE_XCONTRIB:=applications/}
DISTFILES=	xli.1.16.tar.gz \
		xli-png.tar.gz

MAINTAINER=	packages@netbsd.org
COMMENT=	Version of xloadimage, an X11 Image Loading Utility

WRKSRC=		${WRKDIR}
USE_IMAKE=	YES

pre-patch:
	@${PATCH} -d ${WRKSRC} -s -p1 < ${WRKSRC}/png.patch

.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
