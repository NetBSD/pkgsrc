# $NetBSD: Makefile,v 1.9 2001/08/06 08:11:41 tron Exp $

DISTNAME=	xli-1.16nb1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		${MASTER_SITE_XCONTRIB:=applications/}
DISTFILES=	xli.1.16.tar.gz \
		xli-png.tar.gz

MAINTAINER=	packages@netbsd.org
COMMENT=	Version of xloadimage, an X11 Image Loading Utility

USE_BUILDLINK_ONLY=	YES
NO_WRKSUBDIR=		YES
USE_IMAKE=		YES

LDFLAGS+=	-L${X11BASE}/lib

pre-patch:
	@${PATCH} -d ${WRKSRC} -s -p1 < ${WRKSRC}/png.patch

.include "../../graphics/png/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
