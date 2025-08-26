# $NetBSD: Makefile,v 1.14 2025/08/26 13:16:22 pin Exp $

DISTNAME=	feluda-1.9.8
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

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
