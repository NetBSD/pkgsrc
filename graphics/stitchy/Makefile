# $NetBSD: Makefile,v 1.8 2025/01/13 20:35:58 pin Exp $

DISTNAME=	Stitchy-0.1.8
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=grimace87/}
GITHUB_PROJECT=	Stitchy
GITHUB_TAG=	ddf5651b3acf833fa76e51f04c0140e66b917231

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/grimace87/Stitchy/
COMMENT=	Simple command line tool to stitch multiple images into one
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stitchy \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
