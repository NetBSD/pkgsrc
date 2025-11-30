# $NetBSD: Makefile,v 1.1 2025/11/30 10:33:19 markd Exp $

DISTNAME=	python_gitlab-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gitlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-gitlab/python-gitlab
COMMENT=	Interact with GitLab API
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

post-install:
	rm -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/docs
	rm -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
