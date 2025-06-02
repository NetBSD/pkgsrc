# $NetBSD: Makefile,v 1.85 2025/06/02 08:36:21 thor Exp $

DISTNAME=	pip-25.1.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/appdirs.py
REPLACE_PYTHON+=	src/pip/_vendor/chardet/cli/chardetect.py
REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f pip3 && ${MV} pip pip${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
