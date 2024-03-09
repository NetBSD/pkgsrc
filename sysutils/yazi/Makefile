# $NetBSD: Makefile,v 1.10 2024/03/09 21:50:33 pin Exp $

DISTNAME=	yazi-0.2.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sxyazi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sxyazi/yazi/
COMMENT=	Blazing fast terminal file manager
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin share/examples/yazi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yazi \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/keymap.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/theme.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/yazi.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi

.include "../../lang/rust/cargo.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
