# $NetBSD: Makefile,v 1.1 2022/05/02 21:01:37 pin Exp $

DISTNAME=	termatrix-1.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=joeledwards/}
GITHUB_TAG=	25d0f655c50d63deaeff1e39a1bf59da927aa3f5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joeledwards/termatrix/
COMMENT=	Cli to simulate the display from The Matrix
LICENSE=	isc

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/termatrix \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
