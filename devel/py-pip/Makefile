# $NetBSD: Makefile,v 1.4 2012/10/31 11:19:33 asau Exp $
#

DISTNAME=	pip-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

PLIST_SUBST+=		PYVERSSUFFIX="${PYVERSSUFFIX}"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
