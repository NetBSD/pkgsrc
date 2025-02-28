# $NetBSD: Makefile,v 1.22 2025/02/28 08:20:18 pin Exp $

DISTNAME=	dust-1.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bootandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/bootandy/dust/
COMMENT=	More intuitive version of du in rust
LICENSE=	apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.85.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.85.0 on amd64

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/dust
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_MAN} ${WRKSRC}/man-page/dust.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dust.1
	${INSTALL_DATA} ${WRKSRC}/config/config.toml \
		${DESTDIR}${PREFIX}/share/examples/dust
	${INSTALL_DATA} ${WRKSRC}/completions/dust.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/dust
	${INSTALL_DATA} ${WRKSRC}/completions/dust.fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/dust.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_dust \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_dust

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
