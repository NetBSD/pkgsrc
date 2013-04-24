# $NetBSD: Makefile,v 1.1 2013/04/24 02:20:39 rodent Exp $

DISTNAME=	ispell-gaeilge-2.0
CATEGORIES=	textproc
MASTER_SITES=	http://borel.slu.edu/~kps/ispell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for ispell

DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

INSTALLATION_DIRS=	lib

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install}

.include "../../mk/bsd.pkg.mk"
