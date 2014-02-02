# $NetBSD: Makefile,v 1.9 2014/02/02 06:58:08 rodent Exp $

DISTNAME=	pip-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX="${PYVERSSUFFIX}"

REPLACE_PYTHON+=	pip/__init__.py pip/_vendor/requests/certs.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
