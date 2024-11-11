# $NetBSD: Makefile,v 1.8 2024/11/11 07:28:32 wiz Exp $

.include "../../emulators/unicorn/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for unicorn
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none
PYSETUPSUBDIR=	bindings/python
MAKE_ENV+=	LIBUNICORN_PATH=${BUILDLINK_PREFIX.unicorn}/lib

.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
