# $NetBSD: Makefile,v 1.13 2026/08/31 08:32:54 pin Exp $

DISTNAME=	gitpane-0.15.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=affromero/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/affromero/gitpane/
COMMENT=	Multi-repo Git workspace dashboard for the terminal
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

RUST_REQ=	1.88.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
