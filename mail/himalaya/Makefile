# $NetBSD: Makefile,v 1.10 2026/02/26 12:51:54 pin Exp $

DISTNAME=	himalaya-1.2.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=pimalaya/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pimalaya/himalaya
COMMENT=	Command-line interface for email management
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

USE_LANGUAGES+=	c c++

.include "cargo-depends.mk"

#RUST_REQ=	1.93.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.93.1 on amd64

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

BIN_CMD=		${WRKSRC}/target/release/himalaya

pre-install:
	cd ${WRKSRC} && ${BIN_CMD} man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC} && ${BIN_CMD} completion bash > himalaya.bash
	cd ${WRKSRC} && ${BIN_CMD} completion fish > himalaya.fish
	cd ${WRKSRC} && ${BIN_CMD} completion zsh > himalaya.zsh
	#cd ${WRKSRC} && ${BIN_CMD} completion elvish > elvish.txt
	#cd ${WRKSRC} && ${BIN_CMD} completion powershell > powershell.txt

do-install:
	${INSTALL_PROGRAM} ${BIN_CMD} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/himalaya.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/himalaya
	${INSTALL_DATA} ${WRKSRC}/himalaya.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/himalaya.fish
	${INSTALL_DATA} ${WRKSRC}/himalaya.zsh ${DESTDIR}${PREFIX}/share/zsh/site-functions/_himalaya

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
