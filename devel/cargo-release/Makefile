# $NetBSD: Makefile,v 1.20 2026/09/22 14:45:08 pin Exp $

DISTNAME=	cargo-release-1.1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=crate-ci/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crate-ci/cargo-release/
COMMENT=	Cargo release subcommand
LICENSE=	apache-2.0 AND mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=	1.92.0
USE_TOOLS+=	pkg-config perl gmake
USE_LANGUAGES+=	c c++

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
