# $NetBSD: Makefile,v 1.12 2005/03/24 21:12:56 wiz Exp $

DISTNAME=	xeukleides.1.0.0
PKGNAME=	xeukleides-1.0.0
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

BUILD_DEPENDS+=	bison>=1.35:../../devel/bison
DEPENDS+=	eukleides>=1.0.1:../../math/eukleides

USE_BUILDLINK3=	yes
USE_X11BASE=	yes
BUILD_TARGET=	xeukleides
USE_GNU_TOOLS+=	make

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
