# $NetBSD: Makefile,v 1.2 2024/03/14 14:40:00 pin Exp $

DISTNAME=	cocogitto-6.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cocogitto/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/cocogitto/cocogitto/
COMMENT=	The Conventional Commits toolbox
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

USE_TOOLS+=	pkg-config

# Rename the binary to avoid potential conflict with devel/py-cogapp.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cog \
		${DESTDIR}${PREFIX}/bin/cocogitto

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
