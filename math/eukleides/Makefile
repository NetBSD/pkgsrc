# $NetBSD: Makefile,v 1.10 2006/02/05 23:10:01 joerg Exp $

DISTNAME=	eukleides.1.0.1
PKGNAME=	eukleides-1.0.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	Euclidean geometry drawing language

BUILD_DEPENDS+= bison>=1.35:../../devel/bison
DEPENDS+=	pstoedit>=3.31:../../graphics/pstoedit

BUILD_TARGET=	eukleides
USE_TOOLS+=	gmake
USE_MAKEINFO=	YES
INFO_FILES=	eukleides.info

.include "../../mk/bsd.pkg.mk"
