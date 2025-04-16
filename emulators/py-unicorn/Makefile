# $NetBSD: Makefile,v 1.10 2025/04/16 12:46:52 adam Exp $

.include "../../emulators/unicorn/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for unicorn
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioningit-[0-9]*:../../devel/py-versioningit
TEST_DEPENDS+=	${PYPKGPREFIX}-capstone>=5.0.1:../../devel/py-capstone

USE_LANGUAGES=	# none
PYSETUPSUBDIR=	bindings/python
MAKE_ENV+=	LIBUNICORN_PATH=${BUILDLINK_PREFIX.unicorn}/lib

.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
