# $NetBSD: Makefile,v 1.1 2014/03/31 08:42:47 richard Exp $

DISTNAME=	python-stdnum-0.9
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-stdnum/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none
EGG_NAME=	${DISTNAME:S/python-/python_/}

DEPENDS+=   ${PYPKGPREFIX}-suds>=0.4:../../net/py-suds

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
