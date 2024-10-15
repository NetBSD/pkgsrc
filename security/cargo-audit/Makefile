# $NetBSD: Makefile,v 1.10 2024/10/15 03:39:30 pin Exp $

DISTNAME=	cargo-audit-0.20.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rustsec/}
GITHUB_TAG=	cargo-audit/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rustsec/cargo-audit/
COMMENT=	Audit Cargo.lock files for crates with security vulnerabilities
LICENSE=	apache-2.0 # or MIT

.include "cargo-depends.mk"

RUST_REQ=		1.70.0
WRKSRC=			${WRKDIR}/rustsec-cargo-audit-v${PKGVERSION_NOREV}
USE_LANGUAGES=		c
INSTALLATION_DIRS=	bin
MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

# error: found a virtual manifest at `.../rustsec-cargo-audit-v0.17.6/Cargo.toml` instead of a package manifest
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-audit ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
