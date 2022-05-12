# $NetBSD: Makefile,v 1.33 2022/05/12 08:20:36 wiz Exp $

DISTNAME=	Babel-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://babel.pocoo.org/
COMMENT=	Collection of tools for internationalizing Python applications
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pytz>=2015.7:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} != 27
# freezegun is only available for python 3
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
.endif

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYSETUPTESTTARGET=	pytest

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybabel pybabel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
