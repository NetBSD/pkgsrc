# $NetBSD: Makefile,v 1.30 2026/06/01 13:50:26 wiz Exp $

DISTNAME=	rpds_py-2026.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpds-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crate-py/rpds
COMMENT=	Python bindings to Rust's persistent data structures (rpds)
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
