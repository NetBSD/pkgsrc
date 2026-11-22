# $NetBSD: Makefile,v 1.8 2026/11/22 15:32:13 drixter Exp $

DISTNAME=	shuck-0.2.11
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ewhauser/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ewhauser/shuck/
COMMENT=	Lightning fast shell linter/formatter/LSP server
LICENSE=	mit

USE_LANGUAGES=	c c++
# jemalloc
USE_TOOLS+=	gmake

CHECK_PORTABILITY_SKIP=	crates/shuck-linter/resources/test/fixtures/portability/*.sh
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/shuck ${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
