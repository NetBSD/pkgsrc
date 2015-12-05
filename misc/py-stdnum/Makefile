# $NetBSD: Makefile,v 1.5 2015/12/05 21:25:50 adam Exp $

DISTNAME=	python-stdnum-0.9
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-stdnum/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-suds

DEPENDS+=   ${PYPKGPREFIX}-suds>=0.4:../../net/py-suds

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
