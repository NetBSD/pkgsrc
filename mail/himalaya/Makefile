# $NetBSD: Makefile,v 1.4 2023/10/24 22:09:43 wiz Exp $

DISTNAME=	himalaya-0.9.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=soywod/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pimalaya.org/himalaya/
COMMENT=	Command-line interface for email management
LICENSE=	mit

USE_LANGUAGES+=	c c++

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/himalaya/completion
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions


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
	${INSTALL_DATA} ${WRKSRC}/himalaya.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/himalaya.fish ${DESTDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${WRKSRC}/himalaya.zsh ${DESTDIR}${PREFIX}/share/examples/himalaya/completion/

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
