# $NetBSD: Makefile,v 1.11 2023/05/16 19:28:17 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	pyvex-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvex/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/pyvex
COMMENT=	Python bindings for Valgrind's VEX IR
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-archinfo>=${ANGR_VERSION}:../../devel/py-archinfo
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.3:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-angr>=${ANGR_VERSION}:../../devel/py-angr

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/pyvex/lib/libpyvex.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/pyvex/lib/libpyvex.dylib
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/*.py

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
