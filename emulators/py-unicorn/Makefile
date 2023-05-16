# $NetBSD: Makefile,v 1.6 2023/05/16 18:51:11 wiz Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../emulators/unicorn/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for unicorn
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYSETUPSUBDIR=	bindings/python
MAKE_ENV+=	LIBUNICORN_PATH=${BUILDLINK_PREFIX.unicorn}/lib

.include "../../emulators/unicorn/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
