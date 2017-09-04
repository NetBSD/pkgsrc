# $NetBSD: Makefile,v 1.7 2017/09/04 18:55:08 wiz Exp $

DISTNAME=	pydot-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erocarrera/pydot
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
