# $NetBSD: Makefile,v 1.15 2002/10/09 13:22:27 wiz Exp $

DISTNAME=	xli-1.16
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
DISTFILES=	xli.1.16.tar.gz \
		xli-png.tar.gz

MAINTAINER=	packages@netbsd.org
COMMENT=	Version of xloadimage, an X11 Image Loading Utility

#SITES_xli-png.tar.gz=	http://pantransit.reptiles.org/prog/
SITES_xli-png.tar.gz=	${MASTER_SITE_BACKUP}

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES
USE_IMAKE=	YES

pre-patch:
	@${PATCH} -d ${WRKSRC} -s -p1 < ${WRKSRC}/png.patch

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
