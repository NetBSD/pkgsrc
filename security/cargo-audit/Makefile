# $NetBSD: Makefile,v 1.3 2022/04/21 07:57:30 wiz Exp $

DISTNAME=	cargo-audit-0.16.0
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-audit ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
