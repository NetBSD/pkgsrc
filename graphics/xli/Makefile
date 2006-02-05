# $NetBSD: Makefile,v 1.32 2006/02/05 23:09:41 joerg Exp $

DISTNAME=	xli-2005-02-27
PKGNAME=	xli-1.17.0
PKGREVISION=	6
CATEGORIES=	graphics x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/xli/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	X11 Image Loading Utility

USE_IMAKE=	YES
INSTALLATION_DIRS+=	lib/X11/app-defaults

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
