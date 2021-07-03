# $NetBSD: Makefile,v 1.4 2021/07/03 10:08:42 pin Exp $

DISTNAME=	viu-1.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=atanunq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/atanunq/viu/
COMMENT=	Simple terminal image viewer written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/viu ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
