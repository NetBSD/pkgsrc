# $NetBSD: Makefile,v 1.14 2025/04/02 11:07:26 pin Exp $

DISTNAME=	cargo-audit-0.21.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rustsec/}
GITHUB_TAG=	cargo-audit/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rustsec/rustsec
COMMENT=	Audit Cargo.lock files for crates with security vulnerabilities
LICENSE=	apache-2.0 # or MIT

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

WRKSRC=		${WRKDIR}/rustsec-cargo-audit-v${PKGVERSION_NOREV}/cargo-audit
USE_LANGUAGES=	c
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUST_REQ=	1.81.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
