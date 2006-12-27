# $NetBSD: Makefile,v 1.35 2006/12/27 13:37:38 joerg Exp $

DISTNAME=	xli-2005-02-27
PKGNAME=	xli-1.17.0
PKGREVISION=	7
CATEGORIES=	graphics x11
MASTER_SITES=	http://pantransit.reptiles.org/prog/xli/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pantransit.reptiles.org/prog/
COMMENT=	X11 Image Loading Utility

USE_IMAKE=	YES
INSTALLATION_DIRS+=	lib/X11/app-defaults

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
