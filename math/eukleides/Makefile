# $NetBSD: Makefile,v 1.7 2004/12/31 12:36:44 kristerw Exp $
# FreeBSD Id: ports/math/eukleides/Makefile,v 1.1 2002/06/04 18:40:20 ijliao Exp

DISTNAME=	eukleides.1.0.1
PKGNAME=	eukleides-1.0.1
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
