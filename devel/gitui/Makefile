# $NetBSD: Makefile,v 1.7 2023/08/30 20:08:36 pin Exp $

DISTNAME=	gitui-0.24.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=extrawurst/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/extrawurst/gitui/
COMMENT=	Terminal UI for git
LICENSE=	mit

.include "cargo-depends.mk"

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
