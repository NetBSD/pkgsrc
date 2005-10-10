# $NetBSD: Makefile,v 1.30 2005/10/10 19:54:13 reed Exp $

DISTNAME=	xli-2005-02-27
PKGNAME=	xli-1.17.0
PKGREVISION=	4
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
