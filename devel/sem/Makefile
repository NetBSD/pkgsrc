# $NetBSD: Makefile,v 1.6 2026/08/17 07:14:26 pin Exp $

DISTNAME=	sem-0.22.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ataraxy-Labs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ataraxy-labs.github.io/sem/
COMMENT=	Semantic version control
LICENSE=	apache-2.0 OR mit

USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/crates/sem-cli

# needed for 'print-cargo-depends'
#WRKSRC=		${WRKDIR}/${DISTNAME}/crates

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

.include "cargo-crates.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
