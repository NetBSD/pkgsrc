# $NetBSD: Makefile,v 1.15 2024/07/13 05:20:38 adam Exp $

DISTNAME=	oxipng-9.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shssoichiro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shssoichiro/oxipng
COMMENT=	Multithreaded PNG optimizer
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/oxipng \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
