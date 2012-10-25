# $NetBSD: Makefile,v 1.14 2012/10/25 06:55:58 asau Exp $

DISTNAME=	ispell-gaeilge-2.0
CATEGORIES=	textproc
MASTER_SITES=	http://borel.slu.edu/~kps/ispell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

INSTALLATION_DIRS=	lib

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install}

.include "../../mk/bsd.pkg.mk"
