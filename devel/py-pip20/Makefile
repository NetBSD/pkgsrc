# $NetBSD: Makefile,v 1.5 2023/03/29 09:34:08 wiz Exp $

DISTNAME=	pip-20.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement (for Python 2.x)
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/appdirs.py
REPLACE_PYTHON+=	src/pip/_vendor/chardet/cli/chardetect.py
REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"
FILES_SUBST+=  PYMAJORVERSION=${PYTHON_VERSION:C/^([0-9]).*/\1/}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f pip pip[2-3]

# no tests included
do-test:
	${DO_NADA}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
