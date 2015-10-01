# $NetBSD: Makefile,v 1.13 2015/10/01 23:11:41 rodent Exp $

DISTNAME=	pip-7.1.2
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
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip[2-3]

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
