# $NetBSD: Makefile,v 1.14 2017/03/01 13:08:43 fhajny Exp $

DISTNAME=	pylint-1.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-astroid>=1.4.5<1.5.0:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
.if ${PYVERSSUFFIX} == "2.7"
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache-[0-9]*:../../devel/py-backports.functools_lru_cache
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
.endif

USE_LANGUAGES=	# none

SCRIPTS=	epylint pylint pylint-gui pyreverse symilar

INSTALLATION_DIRS=	${PKGMANDIR}/man1

REPLACE_PYTHON+=	pylint/test/data/ascript

pre-configure:
.for file in ${SCRIPTS}
	${MV} ${WRKSRC}/bin/${file} ${WRKSRC}/bin/${file}${PYVERSSUFFIX}
.endfor

post-install:
.for file in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/man/${file}.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${file}${PYVERSSUFFIX}.1
.endfor

do-test:
	${RUN} cd ${WRKSRC}/pylint/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -p "unittest*.py"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
