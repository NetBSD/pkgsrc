# $NetBSD: Makefile,v 1.17 2016/11/06 00:32:12 wen Exp $

DISTNAME=	pip-9.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

REPLACE_PYTHON+=	pip/__init__.py pip/_vendor/requests/certs.py
REPLACE_PYTHON+=	pip/_vendor/requests/packages/chardet/chardetect.py

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip[2-3]

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
