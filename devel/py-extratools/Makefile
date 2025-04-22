# $NetBSD: Makefile,v 1.4 2025/04/22 15:01:57 adam Exp $

DISTNAME=	extratools-0.8.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/extratools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/chuanconggao/extratools
COMMENT=	Extra functional tools beyond standard libraries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.5.10:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.9.0:../../devel/py-toolz

USE_LANGUAGES=	# none

CHECK_INTERPRETER_SKIP=		*.js

post-install:
.for cmd in extratools-flatten extratools-remap extratools-teststats
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} ${cmd} ${cmd}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
