# $NetBSD: Makefile,v 1.9 2022/07/08 14:49:28 wiz Exp $

DISTNAME=	pytest-4.6.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pytest.org/
COMMENT=	Python testing tool
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm5
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.0:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-funcsigs>=1.0:../../devel/py-funcsigs
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata2
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools2
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging2
DEPENDS+=	${PYPKGPREFIX}-pathlib2>=2.2.0:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.12:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-py>=1.5.0:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-argcomplete-[0-9]*:../../devel/py-argcomplete
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis4
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
# does not support python 2.7
#TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:build

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} py.test py.test-${PYVERSSUFFIX} && \
	${MV} pytest pytest-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/testing && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
