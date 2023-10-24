# $NetBSD: Makefile,v 1.2 2023/10/24 22:08:55 wiz Exp $

DISTNAME=	pijul-1.0.0-beta.2
PKGNAME=	pijul-1.0.0.beta2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://static.crates.io/crates/pijul/
DISTFILES=	pijul-1.0.0-beta.2.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pijul.org/
COMMENT=	Distributed version control system
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=		DEP_SODIUM_INCLUDE=${BUILDLINK_PREFIX.libsodium}/include
MAKE_ENV+=		DEP_SODIUM_LIB=${BUILDLINK_PREFIX.libsodium}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zstd}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.xxhash}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pijul ${DESTDIR}${PREFIX}/bin

.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
