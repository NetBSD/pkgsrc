# $NetBSD: Makefile,v 1.1 2022/01/19 21:14:26 rhialto Exp $

DISTNAME=	trio-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-trio/trio
COMMENT=	Friendly Python library for async concurrency and I/O
LICENSE=	mit OR apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	37 27

DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.2.2:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.9:../../devel/py-async_generator
DEPENDS+=	${PYPKGPREFIX}-idna>=2.10:../../www/py-idna
#DEPENDS+=	${PYPKGPREFIX}-outcome>=1.1.0:../../wip/py-outcome
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.2.0:../../misc/py-sniffio
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.14:../../devel/py-cffi

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
