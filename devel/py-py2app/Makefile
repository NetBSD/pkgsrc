# $NetBSD: Makefile,v 1.8 2017/09/04 18:08:21 wiz Exp $

DISTNAME=	py2app-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py2app/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ronaldoussoren/py2app
COMMENT=	Create standalone Mac OS X applications with Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.10.1:../../graphics/py-altgraph
DEPENDS+=	${PYPKGPREFIX}-modulegraph>=0.10.1:../../devel/py-modulegraph
DEPENDS+=	${PYPKGPREFIX}-macholib>=1.5:../../devel/py-macholib

ONLY_FOR_PLATFORM=	Darwin-*-*

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/py2applet \
		${DESTDIR}${PREFIX}/bin/py2applet${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
