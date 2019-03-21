# $NetBSD: Makefile,v 1.2 2019/03/21 21:49:00 adam Exp $

DISTNAME=	extratools-0.8.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/extratools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chuanconggao/extratools
COMMENT=	Extra functional tools beyond standard libraries
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.5.10:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.9.0:../../devel/py-toolz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
CHECK_INTERPRETER_SKIP=		*.js

post-install:
.for cmd in extratools-flatten extratools-remap extratools-teststats
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} ${cmd} ${cmd}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
