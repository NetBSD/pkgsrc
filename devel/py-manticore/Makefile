# $NetBSD: Makefile,v 1.20 2023/11/03 09:59:07 wiz Exp $

DISTNAME=	manticore-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/manticore/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/trailofbits/manticore
COMMENT=	Symbolic execution tool for analysis of binaries and smart contracts
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-crytic-compile>=0.2.2:../../finance/py-crytic-compile
DEPENDS+=	${PYPKGPREFIX}-intervaltree-[0-9]*:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-protobuf-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-pyevmasm>=0.2.3:../../finance/py-pyevmasm
DEPENDS+=	${PYPKGPREFIX}-pysha3-[0-9]*:../../devel/py-pysha3
DEPENDS+=	${PYPKGPREFIX}-prettytable-[0-9]*:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-rlp-[0-9]*:../../devel/py-rlp
DEPENDS+=	${PYPKGPREFIX}-wasm-[0-9]*:../../devel/py-wasm
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-z3-[0-9]*:../../math/py-z3
# native
DEPENDS+=	${PYPKGPREFIX}-capstone>=4.0.2:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 311 312

post-install:
.for bin in manticore manticore-verifier
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
