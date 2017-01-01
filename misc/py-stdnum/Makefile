# $NetBSD: Makefile,v 1.10 2017/01/01 14:43:48 wiz Exp $

DISTNAME=	python-stdnum-1.4
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-stdnum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-simplesoap-[0-9]*:../../net/py-simplesoap

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-simplesoap

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
