# $NetBSD: Makefile,v 1.39 2026/09/18 14:48:54 pin Exp $

DISTNAME=	yazi-26.9.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sxyazi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sxyazi/yazi/
COMMENT=	Blazing fast terminal file manager
LICENSE=	mit

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
RATATUI-CORE_REV=	dde5e05eccfe5b7cb7712b4bdf76edd0c2cd1f25	
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		ratatui-core-${RATATUI-CORE_REV}.tar.gz
SITES.ratatui-core-${RATATUI-CORE_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=yazi-rs/}ratatui/archive/${RATATUI-CORE_REV}.tar.gz

RUST_REQ=	1.95.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

# https://github.com/sxyazi/yazi/issues/4251
MAKE_ENV+=	VERGEN_GIT_SHA=12345

INSTALLATION_DIRS=	bin share/applications share/examples/yazi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/yazi \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ya \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/keymap-default.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/theme-dark.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/theme-light.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/yazi-config/preset/yazi-default.toml \
		${DESTDIR}${PREFIX}/share/examples/yazi
	${INSTALL_DATA} ${WRKSRC}/assets/yazi.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../lang/rust/cargo.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
