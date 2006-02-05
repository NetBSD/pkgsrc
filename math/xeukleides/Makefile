# $NetBSD: Makefile,v 1.15 2006/02/05 23:10:04 joerg Exp $

DISTNAME=	xeukleides.1.0.0
PKGNAME=	xeukleides-1.0.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

BUILD_DEPENDS+=	bison>=1.35:../../devel/bison
DEPENDS+=	eukleides>=1.0.1:../../math/eukleides

USE_X11BASE=	yes
BUILD_TARGET=	xeukleides
USE_TOOLS+=	gmake

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
