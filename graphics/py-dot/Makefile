# $NetBSD: Makefile,v 1.2 2014/05/09 07:37:07 wiz Exp $

DISTNAME=	pydot-1.0.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	http://pydot.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pydot/
COMMENT=	Python interface to Graphviz's Dot language
LICENSE=      	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.0.28

post-install:
	${RM} ${DESTDIR}${PREFIX}/README
	${RM} ${DESTDIR}${PREFIX}/LICENSE

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
