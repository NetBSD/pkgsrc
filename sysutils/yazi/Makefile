# $NetBSD: Makefile,v 1.1 2023/09/19 07:06:00 pin Exp $

DISTNAME=	yazi-0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sxyazi/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
# We need to fetch the sources from this specific hash as
# it includes fixes for NetBSD not present in the release tag.
GITHUB_TAG=	6d2f69b612a363be73f47d7cd3c5272e20897fc4

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sxyazi/yazi/
COMMENT=	Blazing fast terminal file manager
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/yazi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yazi \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/config/preset/keymap.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/config/preset/theme.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/config/preset/yazi.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
