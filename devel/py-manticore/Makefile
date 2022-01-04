# $NetBSD: Makefile,v 1.16 2022/01/04 20:53:16 wiz Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	manticore-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}
GITHUB_PROJECT=	manticore
GITHUB_TAG=	0.3.4

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/trailofbits/manticore/
COMMENT=	Symbolic execution tool for analysis of binaries and smart contracts
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-angr>=${ANGR_VERSION}:../../devel/py-angr
DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-rlp-[0-9]*:../../devel/py-rlp
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-pysha3-[0-9]*:../../devel/py-pysha3
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn
DEPENDS+=	${PYPKGPREFIX}-crytic-compile-[0-9]*:../../finance/py-crytic-compile
DEPENDS+=	${PYPKGPREFIX}-pyevmasm-[0-9]*:../../finance/py-pyevmasm
DEPENDS+=	${PYPKGPREFIX}-z3solver-[0-9]*:../../math/py-z3solver
DEPENDS+=	${PYPKGPREFIX}-ptable-[0-9]*:../../textproc/py-ptable
DEPENDS+=	${PYPKGPREFIX}-wasm-[0-9]*:../../devel/py-wasm
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for alternative in bin/manticore bin/manticore-verifier
	${MV} ${DESTDIR}${PREFIX}/${alternative} \
		${DESTDIR}${PREFIX}/${alternative}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
