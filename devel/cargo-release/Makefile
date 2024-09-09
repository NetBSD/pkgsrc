# $NetBSD: Makefile,v 1.2 2024/09/09 19:15:46 pin Exp $

DISTNAME=	cargo-release-0.25.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=crate-ci/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/crate-ci/cargo-release/
COMMENT=	Cargo release subcommand
LICENSE=	apache-2.0 AND mit

SITES.curl-sys-0.4.74+curl-8.9.0.crate=	https://static.crates.io/crates/curl-sys/

.include "cargo-depends.mk"

RUST_REQ=	1.78.0
USE_TOOLS+=	pkg-config perl gmake
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
