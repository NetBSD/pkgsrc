# $NetBSD: Makefile,v 1.2 2026/11/04 16:56:37 drixter Exp $

DISTNAME=	proc-cli-2.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=yazeed/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	me@yazeed.com
HOMEPAGE=	https://proc-cli.com/
COMMENT=	Semantic CLI tool for process management
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

PROC=		${WRKSRC}/target/release/proc

post-build:
	@${STEP_MSG} "Creating manual page..."
	${RUN}${PROC} manpage > ${WRKDIR}/proc.1
	@${STEP_MSG} "Creating completion rules..."
	${RUN}${PROC} completions bash > ${WRKDIR}/proc-completion.bash
	${RUN}${PROC} completions fish > ${WRKDIR}/proc-completion.fish
	${RUN}${PROC} completions zsh > ${WRKDIR}/proc-completion.zsh

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_MAN} ${WRKDIR}/proc.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/proc.1
	${INSTALL_DATA} ${WRKDIR}/proc-completion.bash \
	  ${DESTDIR}${PREFIX}/share/bash-completion/completions/proc
	${INSTALL_DATA} ${WRKDIR}/proc-completion.fish \
	  ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/proc.fish
	${INSTALL_DATA} ${WRKDIR}/proc-completion.zsh \
	  ${DESTDIR}${PREFIX}/share/zsh/site-functions/_proc

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
