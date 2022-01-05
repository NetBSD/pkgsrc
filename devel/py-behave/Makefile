# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:01 wiz Exp $

DISTNAME=	behave-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/behave/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/behave/behave
COMMENT=	Behaviour-driven development
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-parse>=1.8.2:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-parse_type>=0.4.2:../../textproc/py-parse_type
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-hamcrest>=1.8:../../devel/py-hamcrest
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-path>=10.1:../../devel/py-path
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-parse_type

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} behave behave-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
