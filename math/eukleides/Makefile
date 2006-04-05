# $NetBSD: Makefile,v 1.12 2006/04/05 22:35:50 jlam Exp $

DISTNAME=	eukleides.1.0.1
PKGNAME=	eukleides-1.0.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	Euclidean geometry drawing language

DEPENDS+=	pstoedit>=3.31:../../graphics/pstoedit

BUILD_TARGET=	eukleides
USE_TOOLS+=	bison gmake makeinfo
INFO_FILES=	eukleides.info

.include "../../mk/bsd.pkg.mk"
