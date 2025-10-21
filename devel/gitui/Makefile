# $NetBSD: Makefile,v 1.18 2025/10/21 08:44:04 wiz Exp $

DISTNAME=	gitui-0.27.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=extrawurst/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/extrawurst/gitui/
COMMENT=	Terminal UI for git
LICENSE=	mit

# https://github.com/gitui-org/gitui/issues/2742
BROKEN=		"Does not build with rust 1.90"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "cargo-depends.mk"

RUST_REQ=		1.70.0
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config perl gmake

INSTALLATION_DIRS=	bin share/doc/gitui share/examples/gitui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gitui \
		${DESTDIR}${PREFIX}/bin
	for i in KEY_CONFIG.md LICENSE.md README.md THEMES.md; do \
		${INSTALL_DATA} ${WRKSRC}/$$i \
		    ${DESTDIR}${PREFIX}/share/doc/gitui/$$i; \
	done
	for i in vim_style_key_config.ron; do \
		${INSTALL_DATA} ${WRKSRC}/$$i \
		    ${DESTDIR}${PREFIX}/share/examples/gitui/$$i; \
	done

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
