# $NetBSD: Makefile,v 1.3 2021/07/05 09:09:23 pin Exp $

DISTNAME=	oxipng-4.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shssoichiro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
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
