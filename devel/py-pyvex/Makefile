# $NetBSD: Makefile,v 1.13 2024/11/11 07:28:21 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	pyvex-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvex/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/pyvex
COMMENT=	Python bindings for Valgrind's VEX IR
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=59:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.3:../../devel/py-cffi

USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/pyvex/lib/libpyvex.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/pyvex/lib/libpyvex.dylib
.endif

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
