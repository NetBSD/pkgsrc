# $NetBSD: Makefile,v 1.2 2021/04/24 19:52:59 pin Exp $

DISTNAME=	oxipng-4.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shssoichiro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shssoichiro/oxipng/
COMMENT=	Multithreaded PNG optimizer
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/oxipng ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
