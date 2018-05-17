# $NetBSD: Makefile,v 1.1 2018/05/17 15:47:46 minskim Exp $

DISTNAME=	llvmlite-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=numba/}
GITHUB_PROJECT=	llvmlite
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvmlite.pydata.org/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c++

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-enum-[0-9]*:../../devel/py-enum
.endif

BUILDLINK_API_DEPENDS.llvm+=	llvm>=5.0.0
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
