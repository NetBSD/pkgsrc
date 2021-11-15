# $NetBSD: Makefile,v 1.16 2021/11/15 22:54:03 wiz Exp $

DISTNAME=	librespot-0.3.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=librespot-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/librespot-org/librespot/
COMMENT=	Open Source Spotify client library
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	yes

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/librespot ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
