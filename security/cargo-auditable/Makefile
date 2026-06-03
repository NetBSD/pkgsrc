# $NetBSD: Makefile,v 1.2 2026/06/03 20:09:26 pin Exp $

DISTNAME=	cargo-auditable-0.7.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-secure-code/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/rust-secure-code/cargo-auditable/
COMMENT=	Make production Rust binaries auditable
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

#RUST_REQ=	1.97.0-beta.2
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.97.0-beta.2 on amd64
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-auditable \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cargo-auditable/cargo-auditable.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/cargo-auditable.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
