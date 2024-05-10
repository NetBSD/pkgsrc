# $NetBSD: Makefile,v 1.30 2024/05/10 06:46:01 fox Exp $

DISTNAME=	eza-0.18.15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=eza-community/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
SUPERSEDES=	exa-[0-9]*

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://eza.rocks/
COMMENT=	Modern, maintained replacement for ls
LICENSE=	mit

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

post-build:
	${CP} ${FILESDIR}/eza.1 ${WRKDIR}/eza.1
	${CP} ${FILESDIR}/eza_colors-explanation.5 ${WRKDIR}/eza_colors-explanation.5
	${CP} ${FILESDIR}/eza_colors.5 ${WRKDIR}/eza_colors.5

post-install:
	${INSTALL_MAN} ${WRKDIR}/eza.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKDIR}/eza_colors-explanation.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKDIR}/eza_colors.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/completions/bash/eza \
			${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/eza.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_eza \
			${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
