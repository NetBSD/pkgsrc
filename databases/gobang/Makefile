# $NetBSD: Makefile,v 1.2 2021/09/15 14:08:54 wiz Exp $

DISTNAME=	gobang-v0.1.0-alpha.5
PKGNAME=	gobang-0.1.0alpha5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=TaKO8Ki/}
GITHUB_TAG=	v0.1.0-alpha.5

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/TaKO8Ki/gobang/
COMMENT=	Cross-platform TUI database management tool
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gobang ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
