# $NetBSD: Makefile,v 1.17 2007/12/02 08:32:24 rillig Exp $

DISTNAME=	xeukleides.1.0.0
PKGNAME=	xeukleides-1.0.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://perso.orange.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.orange.fr/obrecht/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

BUILD_DEPENDS+=	bison>=1.35:../../devel/bison
DEPENDS+=	eukleides>=1.0.1:../../math/eukleides

USE_X11BASE=	yes
BUILD_TARGET=	xeukleides
USE_TOOLS+=	gmake flex

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
