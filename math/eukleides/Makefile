# $NetBSD: Makefile,v 1.11 2006/03/05 16:27:27 jlam Exp $

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
USE_TOOLS+=	gmake makeinfo
INFO_FILES=	eukleides.info

.include "../../mk/bsd.pkg.mk"
