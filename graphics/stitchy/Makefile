# $NetBSD: Makefile,v 1.7 2024/05/12 08:37:05 pin Exp $

DISTNAME=	Stitchy-0.1.7
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=grimace87/}
GITHUB_PROJECT=	Stitchy
GITHUB_TAG=	a9fd5f00817af20f1381cf0649a5b228b0208338

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
