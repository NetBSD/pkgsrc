# $NetBSD: Makefile,v 1.3 2023/12/22 18:23:40 zafer Exp $

DISTNAME=	ispell-gaeilge-2.0
PKGNAME=	${DISTNAME:S/eilge//1}
CATEGORIES=	textproc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for ispell

CONFLICTS+=	ispell-gaeilge-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

INSTALLATION_DIRS=	lib

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install}

.include "../../mk/bsd.pkg.mk"
