# $NetBSD: Makefile,v 1.1 2018/08/28 09:58:54 adam Exp $

DISTNAME=	behave-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/behave/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/behave/behave
COMMENT=	Behaviour-driven development
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-parse>=1.8.2:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-parse_type>=0.4.2:../../textproc/py-parse_type
DEPENDS+=	${PYPKGPREFIX}-six>=1.11:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-hamcrest>=1.8:../../devel/py-hamcrest
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-path.py>=10.1:../../devel/py-path.py
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-traceback2-[0-9]*:../../devel/py-traceback2
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} behave behave-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
