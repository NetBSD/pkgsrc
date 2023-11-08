# $NetBSD: Makefile,v 1.9 2023/11/08 13:18:23 wiz Exp $

DISTNAME=	gobang-0.1.0alpha5
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=TaKO8Ki/}
GITHUB_TAG=	v0.1.0-alpha.5

MAINTAINER=	pkgsrc-users@NetBSD.org
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
