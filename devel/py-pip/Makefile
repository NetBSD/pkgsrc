# $NetBSD: Makefile,v 1.71 2023/12/17 19:09:12 adam Exp $

DISTNAME=	pip-23.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/appdirs.py
REPLACE_PYTHON+=	src/pip/_vendor/chardet/cli/chardetect.py
REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
FILES_SUBST+=  PYMAJORVERSION=${PYTHON_VERSION:C/^([0-9]).*/\1/}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f pip pip[2-3]
	${CHMOD} -R go-w ${DESTDIR}${PREFIX}/${PYSITELIB}

# no tests included
do-test:
	${DO_NADA}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
