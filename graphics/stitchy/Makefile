# $NetBSD: Makefile,v 1.1 2021/01/01 17:18:06 pin Exp $

DISTNAME=	Stitchy-0.1.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=grimace87/}
GITHUB_PROJECT=	Stitchy
GITHUB_TAG=	86c57866ff2186e765ab7a2877a2103689611290

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/grimace87/Stitchy/
COMMENT=	Simple command line tool to stitch multiple images into one
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stitchy ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
