# $NetBSD: Makefile,v 1.11 2021/11/01 18:58:33 wiz Exp $

DISTNAME=	pydot-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erocarrera/pydot
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=	mit

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

PYTHON_VERSIONED_DEPENDENCIES+=	pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
