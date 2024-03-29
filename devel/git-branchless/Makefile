# $NetBSD: Makefile,v 1.7 2023/11/08 13:18:44 wiz Exp $

DISTNAME=	git-branchless-0.8.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arxanas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arxanas/git-branchless/
COMMENT=	High-velocity, monorepo-scale workflow for Git
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
USE_NCURSES=	yes #NCURSES_MOUSE_VERSION

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/ioctl-rs-0.1.6/src/os/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-branchless \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
