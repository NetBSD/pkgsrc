# $NetBSD: Makefile,v 1.6 2004/12/03 15:15:03 wiz Exp $
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

BUILD_TARGET=	eukleides
USE_GNU_TOOLS+=	make
USE_MAKEINFO=	YES
INFO_FILES=	eukleides.info

.include "../../mk/bsd.pkg.mk"
