# $NetBSD: Makefile,v 1.5 2022/09/27 07:44:28 pin Exp $

DISTNAME=	termatrix-2.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=joeledwards/}
GITHUB_TAG=	ada1c5c5dbd0f73e0208999dc9dffb08041d8ce3

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
