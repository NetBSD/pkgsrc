# $NetBSD: Makefile,v 1.8 2004/04/25 04:00:19 snj Exp $
# FreeBSD Id: ports/math/eukleides/Makefile,v 1.1 2002/06/04 18:40:20 ijliao Exp

DISTNAME=	xeukleides.0.9.0
PKGNAME=	xeukleides-0.9.0
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

BUILD_DEPENDS+=	bison>=1.35:../../devel/bison
DEPENDS+=	eukleides>=0.9.0:../../math/eukleides

USE_BUILDLINK3=	yes
USE_MAKEINFO=	yes
USE_X11BASE=	yes
ALL_TARGET=	xeukleides
USE_GNU_TOOLS+=	make

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
