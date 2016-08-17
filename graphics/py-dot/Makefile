# $NetBSD: Makefile,v 1.5 2016/08/17 12:37:34 richard Exp $

DISTNAME=	pydot-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pydot/
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=      	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

post-install:
	${RM} ${DESTDIR}${PREFIX}/README.md
	${RM} ${DESTDIR}${PREFIX}/LICENSE

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
