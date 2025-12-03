# $NetBSD: Makefile,v 1.2 2025/12/03 09:59:01 adam Exp $

DISTNAME=	python_gitlab-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gitlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-gitlab/python-gitlab
COMMENT=	Interact with GitLab API
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=1.0.0:../../devel/py-requests-toolbelt
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.24.1:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-respx>=0.22.0:../../www/py-respx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} gitlab gitlab-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
