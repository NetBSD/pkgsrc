# $NetBSD: Makefile,v 1.5 2020/03/08 16:42:26 bsiegert Exp $

DISTNAME=	pyvex-8.20.1.7
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	pyvex
GITHUB_TAG=	4fa68d58618a7635b281c9d06263c75fb9bf357f

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/pyvex/
COMMENT=	Python bindings for Valgrind's VEX IR
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

DEPENDS+=	${PYPKGPREFIX}-archinfo-[0-9]*:../../devel/py-archinfo
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "vex-inplace.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
