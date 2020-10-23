# $NetBSD: Makefile,v 1.1 2020/10/23 20:50:16 pin Exp $

DISTNAME=	kiro-editor-0.4.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhysd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/rhysd/kiro-editor/
COMMENT=	Terminal UTF-8 text editor written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++ # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/kiro ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
