# $NetBSD: Makefile,v 1.7 2023/10/24 22:10:45 wiz Exp $

DISTNAME=	cargo-audit-0.17.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rustsec/}
GITHUB_TAG=	cargo-audit/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rustsec/cargo-audit/
COMMENT=	Audit Cargo.lock files for crates with security vulnerabilities
LICENSE=	apache-2.0 # or MIT

.include "cargo-depends.mk"

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
