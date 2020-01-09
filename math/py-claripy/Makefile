# $NetBSD: Makefile,v 1.2 2020/01/09 14:02:32 wiz Exp $

DISTNAME=	claripy-8.20.1.7
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	claripy
GITHUB_TAG=	ea20bb80a84aab942f89cffbf035675dc0cf1af4

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/claripy/
COMMENT=	Abstraction layer for constraint solvers
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
