# $NetBSD: Makefile,v 1.17 2019/01/17 13:19:36 adam Exp $

DISTNAME=	setuptools_scm-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
# Mercurial only supports Python 2.7 and we only need 'hg' command
TEST_DEPENDS+=	py27-mercurial-[0-9]*:../../devel/py-mercurial

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
