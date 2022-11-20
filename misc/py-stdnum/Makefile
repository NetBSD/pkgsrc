# $NetBSD: Makefile,v 1.22 2022/11/20 19:15:43 adam Exp $

DISTNAME=	python-stdnum-1.18
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-stdnum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
