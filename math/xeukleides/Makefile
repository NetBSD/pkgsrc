# $NetBSD: Makefile,v 1.1.1.1 2002/12/07 18:13:51 cjep Exp $
# FreeBSD Id: ports/math/eukleides/Makefile,v 1.1 2002/06/04 18:40:20 ijliao Exp

DISTNAME=	xeukleides.0.9.0
PKGNAME=	xeukleides-0.9.0
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

BUILD_DEPENDS+=	bison>=1.35:../../devel/bison
DEPENDS+=	eukleides>=0.9.0:../../math/eukleides

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
ALL_TARGET=	xeukleides
USE_GMAKE=	yes

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/x11.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
