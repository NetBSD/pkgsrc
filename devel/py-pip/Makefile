# $NetBSD: Makefile,v 1.80 2025/02/02 16:10:42 wiz Exp $

DISTNAME=	pip-25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=67.6.1:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/appdirs.py
REPLACE_PYTHON+=	src/pip/_vendor/chardet/cli/chardetect.py
REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

.include "../../lang/python/pyversion.mk"
FILES_SUBST+=  PYMAJORVERSION=${PYTHON_VERSION:C/^([0-9]).*/\1/}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f pip3 && ${MV} pip pip-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
