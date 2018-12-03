# $NetBSD: Makefile,v 1.3 2018/12/03 19:34:39 adam Exp $

DISTNAME=	requests-futures-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-futures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ross/requests-futures
COMMENT=	Asynchronous Python HTTP for Humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.0:../../devel/py-requests

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-futures>=2.1.3:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
