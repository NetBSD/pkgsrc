# $NetBSD: Makefile,v 1.7 2016/07/09 13:03:57 wiz Exp $

DISTNAME=	python-stdnum-0.9
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-stdnum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-suds

DEPENDS+=   ${PYPKGPREFIX}-suds>=0.4:../../net/py-suds

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
