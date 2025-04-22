# $NetBSD: Makefile,v 1.2 2025/04/22 20:27:04 wiz Exp $

DISTNAME=	hawkauthlib-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hawkauthlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla-services/hawkauthlib
COMMENT=	Hawk Access Authentication protocol
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

# as of 2.0.0
# 14 failed, 14 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
