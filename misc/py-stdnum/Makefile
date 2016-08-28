# $NetBSD: Makefile,v 1.9 2016/08/28 15:48:33 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-simplesoap

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
