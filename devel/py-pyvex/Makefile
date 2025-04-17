# $NetBSD: Makefile,v 1.14 2025/04/17 16:06:22 adam Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	pyvex-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvex/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/pyvex
COMMENT=	Python bindings for Valgrind's VEX IR
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.3:../../devel/py-cffi

USE_TOOLS+=	gmake
MAKE_ENV+=	PYSITELIB=${PYSITELIB}

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
