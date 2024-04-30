# $NetBSD: Makefile,v 1.16 2024/04/30 09:58:52 pin Exp $

DISTNAME=	csview-1.3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wfxr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/wfxr/csview/
COMMENT=	High performance csv viewer with cjk/emoji support
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

#INSTALLATION_DIRS=	bin
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/csview \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/completions/bash/csview.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_csview \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/completions/fish/csview.fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
