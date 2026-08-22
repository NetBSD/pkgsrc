# $NetBSD: Makefile,v 1.7 2026/08/22 17:35:28 pin Exp $

DISTNAME=	sem-0.23.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ataraxy-Labs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ataraxy-labs.github.io/sem/
COMMENT=	Semantic version control
LICENSE=	apache-2.0 OR mit

USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/crates/sem-cli

#RUST_REQ=	1.99.0-beta.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.99.0-beta.1 on amd64

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib

CONFLICTS+=	parallel-[0-9]*

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

CARGO_NO_DEFAULT_FEATURES=	YES

post-build:
	cd ${WRKDIR}/${DISTNAME}/crates && target/release/sem completions bash > sem.bash
	cd ${WRKDIR}/${DISTNAME}/crates && target/release/sem completions zsh > _sem

post-install:
	cd ${WRKDIR}/${DISTNAME}/crates && ${INSTALL_DATA} sem.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/sem
	cd ${WRKDIR}/${DISTNAME}/crates && ${INSTALL_DATA} _sem ${DESTDIR}${PREFIX}/share/zsh/site-functions/_sem

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
