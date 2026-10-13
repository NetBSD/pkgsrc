# $NetBSD: Makefile,v 1.1 2026/10/13 13:26:28 adam Exp $

DISTNAME=	cargo-llvm-lines-0.4.48
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dtolnay/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dtolnay/cargo-llvm-lines
COMMENT=	Measure instantiations of each generic function
LICENSE=	apache-2.0 OR mit

RUST_REQ=	1.86

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
