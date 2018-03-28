# $NetBSD: Makefile,v 1.3 2018/03/28 01:51:16 khorben Exp $

DISTNAME=	pyvex-7.8.2.21
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	pyvex
GITHUB_TAG=	29e88cbd20d628421a903e3dfec0027dd01be233

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/pyvex/
COMMENT=	Python bindings for Valgrind's VEX IR
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

DEPENDS+=	${PYPKGPREFIX}-archinfo-[0-9]*:../../devel/py-archinfo

PYTHON_VERSIONS_ACCEPTED=	27

.include "vex-inplace.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
