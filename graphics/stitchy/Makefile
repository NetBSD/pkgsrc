# $NetBSD: Makefile,v 1.3 2022/03/06 08:46:01 pin Exp $

DISTNAME=	Stitchy-0.1.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=grimace87/}
GITHUB_PROJECT=	Stitchy
GITHUB_TAG=	48c49c182d11d4f1050a3888362b4166cf0dfe4e

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
