# $NetBSD: Makefile,v 1.7 2026/03/04 14:58:02 pin Exp $

DISTNAME=	cocogitto-7.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cocogitto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cocogitto/cocogitto/
COMMENT=	The Conventional Commits toolbox
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

RUST_REQ=	1.78.0
USE_TOOLS+=	pkg-config

# Rename the binary to avoid potential conflict with devel/py-cogapp.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cog \
		${DESTDIR}${PREFIX}/bin/cocogitto

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
