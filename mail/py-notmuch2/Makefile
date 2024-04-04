# $NetBSD: Makefile,v 1.1 2024/04/04 04:21:19 wiz Exp $

PYTHON_FOR_BUILD_ONLY=		no

.include "../../mail/notmuch/Makefile.common"

WHEEL_NAME=	${DISTNAME:S/notmuch-/notmuch2-/}
PKGNAME=	${PYPKGPREFIX}-${WHEEL_NAME}
CATEGORIES+=	python

MAINTAINER=	mdehling@gmail.com
COMMENT=	Pythonic bindings for the notmuch mail database using CFFI

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

PYSETUPSUBDIR=	bindings/python-cffi

.include "../../mail/notmuch/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
