# $NetBSD: Makefile,v 1.28 2019/02/09 17:13:59 adam Exp $

DISTNAME=	pip-19.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/appdirs.py
REPLACE_PYTHON+=	src/pip/_vendor/certifi/core.py
REPLACE_PYTHON+=	src/pip/_vendor/chardet/cli/chardetect.py
REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f pip pip[2-3]
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/pip/_vendor && \
		chmod -R go-w .

# no tests included
do-test:
	${DO_NADA}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
