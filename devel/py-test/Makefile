# $NetBSD: Makefile,v 1.1 2013/07/24 10:46:38 drochner Exp $
#

DISTNAME=	pytest-2.3.5
PKGNAME=	${PYPKGPREFIX}-pytest-2.3.5
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/p/pytest/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pytest
COMMENT=	Python testing tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
