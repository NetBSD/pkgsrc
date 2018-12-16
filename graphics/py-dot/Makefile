# $NetBSD: Makefile,v 1.9 2018/12/16 14:19:16 adam Exp $

DISTNAME=	pydot-1.4.1
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
