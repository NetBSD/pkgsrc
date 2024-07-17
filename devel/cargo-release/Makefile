# $NetBSD: Makefile,v 1.1 2024/07/17 12:03:14 pin Exp $

DISTNAME=	cargo-release-0.25.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=crate-ci/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/crate-ci/cargo-release/
COMMENT=	Cargo release subcommand
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config perl gmake
USE_LANGUAGES+=	c c++
RUST_REQ=	1.76.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
