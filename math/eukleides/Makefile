# $NetBSD: Makefile,v 1.2 2003/05/06 23:19:17 seb Exp $
# FreeBSD Id: ports/math/eukleides/Makefile,v 1.1 2002/06/04 18:40:20 ijliao Exp

DISTNAME=	eukleides.0.9.0
PKGNAME=	eukleides-0.9.0
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	Euclidean geometry drawing language

BUILD_DEPENDS+= bison>=1.35:../../devel/bison
DEPENDS+=	pstoedit>=3.31:../../graphics/pstoedit

ALL_TARGET=	eukleides
USE_GMAKE=	yes

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
