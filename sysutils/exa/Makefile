# $NetBSD: Makefile,v 1.8 2021/11/08 05:11:27 fox Exp $

DISTNAME=	exa-0.10.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ogham/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://the.exa.website/
COMMENT=	Replacement for ls(1) written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

post-build:
	${CP} ${FILESDIR}/exa.1 ${WRKDIR}/exa.1
	${CP} ${FILESDIR}/exa_colors.5 ${WRKDIR}/exa_colors.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/exa ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/exa.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/exa_colors.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/completions/completions.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/exa
	${INSTALL_DATA} ${WRKSRC}/completions/completions.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/exa.fish
	${INSTALL_DATA} ${WRKSRC}/completions/completions.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_exa

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
