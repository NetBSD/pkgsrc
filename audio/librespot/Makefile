# $NetBSD: Makefile,v 1.21 2022/07/02 16:53:06 ryoon Exp $

DISTNAME=	librespot-0.4.1
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
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/librespot \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
