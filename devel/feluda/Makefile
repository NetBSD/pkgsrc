# $NetBSD: Makefile,v 1.2 2025/02/06 11:21:24 pin Exp $

DISTNAME=	feluda-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=anistark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anistark/feluda/
COMMENT=	Detect license usage restrictions in your project
LICENSE=	mit AND cc-by-nc-nd-v4.0-license

# Permission to redistribute binaries has been granted by the copyright
# holder: https://github.com/anistark/feluda/issues/9
#
# The package is confirmed to build on NetBSD x86_64.
# If, for any reason patching is needed to support other platforms,
# permission should be granted by upstream before applying any.

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
