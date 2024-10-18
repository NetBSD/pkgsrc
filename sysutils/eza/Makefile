# $NetBSD: Makefile,v 1.41 2024/10/18 12:41:33 fox Exp $

DISTNAME=	eza-0.20.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=eza-community/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://eza.rocks/
COMMENT=	Modern, maintained replacement for ls
LICENSE=	mit

RUST_REQ=	1.70.0
SUPERSEDES=	exa-[0-9]*

DISTFILES=	${DEFAULT_DISTFILES} man-${PKGVERSION_NOREV}.tar.gz
SITES.man-0.20.4.tar.gz=	https://github.com/eza-community/eza/releases/download/v${PKGVERSION_NOREV}/

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

post-install:
	${INSTALL_MAN} ${WRKDIR}/target/man-${PKGVERSION_NOREV}/eza.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/target/man-${PKGVERSION_NOREV}/eza_colors-explanation.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKDIR}/target/man-${PKGVERSION_NOREV}/eza_colors.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/completions/bash/eza \
			${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/eza.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_eza \
			${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
