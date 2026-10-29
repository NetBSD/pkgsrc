# $NetBSD: Makefile,v 1.2 2026/10/29 12:29:45 adam Exp $

DISTNAME=	cachebox-6.2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachebox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/awolverp/cachebox
COMMENT=	Fastest memoizing and caching Python library
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
