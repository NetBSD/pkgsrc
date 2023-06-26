# $NetBSD: Makefile,v 1.4 2023/06/26 16:31:33 schmonz Exp $

DISTNAME=	empty-files-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/empty-files/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/approvals/${GITHUB_PROJECT}
COMMENT=	Null Object pattern for files
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
