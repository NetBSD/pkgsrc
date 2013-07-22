# $NetBSD: Makefile,v 1.1 2013/07/22 12:16:18 richard Exp $
DISTNAME=		pydot-1.0.28
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=	http://pydot.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.google.com/p/pydot/
COMMENT=		Python interface to Graphviz's Dot language
LICENSE=      	mit

PYTHON_VERSIONS_INCLUDE_3X = no
PYDISTUTILSPKG= yes

DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

post-install:
	${RM} ${DESTDIR}${PREFIX}/README
	${RM} ${DESTDIR}${PREFIX}/LICENSE

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
