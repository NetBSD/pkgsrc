# $NetBSD: Makefile,v 1.2 2022/04/20 19:35:08 nikita Exp $

GITHUB_PROJECT=	cargo-audit
DISTNAME=	v0.16.0
GITHUB_TAG=	${GITHUB_PROJECT}/${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,v,,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rustsec/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rustsec/cargo-audit/
COMMENT=	Audit Cargo.lock files for crates with security vulnerabilities
LICENSE=	apache-2.0 # or MIT

.include "cargo-depends.mk"

WRKSRC=			${WRKDIR}/rustsec-cargo-audit-${DISTNAME}
USE_LANGUAGES=		c
INSTALLATION_DIRS=	bin
MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-audit ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
