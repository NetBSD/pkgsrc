# $NetBSD: Makefile,v 1.8 2018/01/14 11:30:46 adam Exp $

DISTNAME=	pydot-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erocarrera/pydot
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=	mit

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.1.4:../../devel/py-pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
