# $NetBSD: Makefile,v 1.1 2022/08/31 20:29:32 pin Exp $

DISTNAME=	cliris-0.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Kaesebrot84/}
GITHUB_PROJECT=	iris
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Kaesebrot84/iris/
COMMENT=	CLI tool that creates color palettes from images
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cliris \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
