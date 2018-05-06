# $NetBSD: Makefile,v 1.10 2018/05/06 22:20:22 khorben Exp $

DISTNAME=	manticore-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}
GITHUB_PROJECT=	manticore
GITHUB_TAG=	0.1.9

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/trailofbits/manticore/
COMMENT=	Symbolic execution tool for analysis of binaries and smart contracts
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-pysha3-[0-9]*:../../devel/py-pysha3
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn
DEPENDS+=	${PYPKGPREFIX}-z3solver-[0-9]*:../../math/py-z3solver

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
