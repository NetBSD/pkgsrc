# $NetBSD: Makefile,v 1.7 2025/04/14 05:08:08 adam Exp $

DISTNAME=	mohawk-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mohawk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kumar303/mohawk
COMMENT=	Library for Hawk HTTP authorization
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
