# $NetBSD: Makefile,v 1.10 2025/04/02 17:35:36 pin Exp $

DISTNAME=	cargo-release-0.25.17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=crate-ci/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crate-ci/cargo-release/
COMMENT=	Cargo release subcommand
LICENSE=	apache-2.0 AND mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

SITES.curl-sys-0.4.74+curl-8.9.0.crate=	https://static.crates.io/crates/curl-sys/

.include "cargo-depends.mk"

RUST_REQ=	1.82.0
USE_TOOLS+=	pkg-config perl gmake
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
