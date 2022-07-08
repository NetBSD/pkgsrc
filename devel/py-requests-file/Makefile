# $NetBSD: Makefile,v 1.7 2022/07/08 14:33:35 wiz Exp $

DISTNAME=	requests-file-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-file/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dashea/requests-file
COMMENT=	Transport adapter for file:// URLs with the requests python lib
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest tests/test_requests_file.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
