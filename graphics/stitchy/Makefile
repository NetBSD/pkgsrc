# $NetBSD: Makefile,v 1.10 2025/07/26 09:33:06 pin Exp $

DISTNAME=	Stitchy-0.1.10
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=grimace87/}
GITHUB_PROJECT=	Stitchy
GITHUB_TAG=	e84c2c8e8d099bcb36c59fc53a916ea86a5cfd84

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/grimace87/Stitchy/
COMMENT=	Simple command line tool to stitch multiple images into one
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=		1.80.0
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stitchy \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
