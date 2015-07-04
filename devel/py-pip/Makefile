# $NetBSD: Makefile,v 1.12 2015/07/04 14:12:03 bsiegert Exp $

DISTNAME=	pip-1.5.6
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX="${PYVERSSUFFIX}"
FILES_SUBST+=	PYVERSSUFFIX="${PYVERSSUFFIX}"

REPLACE_PYTHON+=	pip/__init__.py pip/_vendor/requests/certs.py
REPLACE_PYTHON+=	pip/_vendor/requests/packages/chardet/chardetect.py

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
