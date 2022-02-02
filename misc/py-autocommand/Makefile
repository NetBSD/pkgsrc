# $NetBSD: Makefile,v 1.1 2022/02/02 18:50:49 adam Exp $

DISTNAME=	autocommand-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autocommand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Lucretiel/autocommand
COMMENT=	Create a command-line program from a function
LICENSE=	gnu-lgpl-v3

TEST_DEPENDS+=	${PYPKGPREFIX}-test>0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
