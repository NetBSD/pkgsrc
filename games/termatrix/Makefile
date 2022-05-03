# $NetBSD: Makefile,v 1.3 2022/05/03 12:58:32 pin Exp $

DISTNAME=	termatrix-1.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=joeledwards/}
GITHUB_TAG=	a104487894b7c581ef6b008367f99e1ed44221d1

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
