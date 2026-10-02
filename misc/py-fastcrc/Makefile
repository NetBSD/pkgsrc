# $NetBSD: Makefile,v 1.1 2026/10/02 07:32:55 adam Exp $

DISTNAME=	fastcrc-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastcrc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/overcat/fastcrc
COMMENT=	Hyper-fast module for computing CRC
LICENSE=	mit

RUST_REQ=	1.89

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
