# $NetBSD: Makefile,v 1.3 2024/11/28 10:17:48 pin Exp $

DISTNAME=	cocogitto-6.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cocogitto/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/cocogitto/cocogitto/
COMMENT=	The Conventional Commits toolbox
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

#RUST_REQ=		1.82.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.82.0 on amd64
USE_TOOLS+=	pkg-config

# Rename the binary to avoid potential conflict with devel/py-cogapp.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cog \
		${DESTDIR}${PREFIX}/bin/cocogitto

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
