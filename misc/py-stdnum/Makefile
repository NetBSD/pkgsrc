# $NetBSD: Makefile,v 1.8 2016/08/18 17:00:38 richard Exp $

DISTNAME=	python-stdnum-1.4
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-stdnum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-simplesoap-[0-9]*:../../net/py-simplesoap

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
