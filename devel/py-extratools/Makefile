# $NetBSD: Makefile,v 1.1 2018/05/25 16:01:06 minskim Exp $

DISTNAME=	extratools-0.6.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/extratools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chuanconggao/extratools
COMMENT=	Extra functional tools beyond standard libraries
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.5.10:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.9.0:../../devel/py-toolz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34 35

post-install:
.for cmd in extratools-flatten extratools-remap extratools-teststats
	${MV} ${DESTDIR}${PREFIX}/bin/${cmd} \
		${DESTDIR}${PREFIX}/bin/${cmd}${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
