# $NetBSD: Makefile,v 1.87 2025/10/28 09:44:51 adam Exp $

DISTNAME=	pip-25.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/appdirs.py
REPLACE_PYTHON+=	src/pip/_vendor/chardet/cli/chardetect.py
REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/pip/_internal && \
	${RM} build_env.py.orig commands/install.py.orig \
		operations/install/wheel.py.orig \
		req/__init__.py.orig req/req_install.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${RM} -f pip3 && ${MV} pip pip${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
