# $NetBSD: Makefile,v 1.19 2026/01/26 10:30:12 pin Exp $

DISTNAME=	feluda-1.11.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=anistark/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anistark/feluda/
COMMENT=	Detect license usage restrictions in your project
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=		1.85.0
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
