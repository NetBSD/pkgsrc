# $NetBSD: Makefile,v 1.9 2022/01/04 20:53:34 wiz Exp $

PKGREVISION= 2
.include "../../devel/py-angr/version.mk"

DISTNAME=	pyvex-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	pyvex
GITHUB_TAG=	v${ANGR_VERSION}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/pyvex/
COMMENT=	Python bindings for Valgrind's VEX IR
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

DEPENDS+=	${PYPKGPREFIX}-ailment>=${ANGR_VERSION}:../../devel/py-ailment
DEPENDS+=	${PYPKGPREFIX}-archinfo>=${ANGR_VERSION}:../../devel/py-archinfo
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.3:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_DEPENDS+=	${PYPKGPREFIX}-angr>=${ANGR_VERSION}:../../devel/py-angr
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} \
	pytest-${PYVERSSUFFIX}

.include "vex-inplace.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
