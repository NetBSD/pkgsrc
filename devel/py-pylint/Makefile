# $NetBSD: Makefile,v 1.15 2017/07/16 20:33:32 adam Exp $

DISTNAME=	pylint-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-astroid>=1.5.1:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
.if ${PYVERSSUFFIX} == "2.7"
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache-[0-9]*:../../devel/py-backports.functools_lru_cache
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../devel/py-singledispatch
.endif

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	pylint/test/data/ascript

post-install:
.for file in epylint pylint pyreverse symilar
	${MV} ${DESTDIR}${PREFIX}/bin/${file} ${DESTDIR}${PREFIX}/bin/${file}${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/man/${file}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${file}${PYVERSSUFFIX}.1
.endfor

do-test:
	cd ${WRKSRC}/pylint/test && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -p "unittest*.py"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
