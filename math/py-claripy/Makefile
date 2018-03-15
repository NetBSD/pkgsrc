# $NetBSD: Makefile,v 1.1 2018/03/15 02:24:18 khorben Exp $

DISTNAME=	claripy-7.8.2.21
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	claripy
GITHUB_TAG=	74a79e034f87369d26846cb7751276b191319e59

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/claripy/
COMMENT=	Abstraction layer for constraint solvers
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
