# $NetBSD: Makefile,v 1.4 2022/09/16 06:36:05 pin Exp $

DISTNAME=	termatrix-2.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=joeledwards/}
GITHUB_TAG=	1c057be9cca5b71d72fed55971b3bc43bfe4d856

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
