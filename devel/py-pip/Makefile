# $NetBSD: Makefile,v 1.7 2014/01/16 02:40:15 rodent Exp $
#

DISTNAME=	pip-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX="${PYVERSSUFFIX}"

REPLACE_PYTHON+=	pip/__init__.py pip/_vendor/requests/certs.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
