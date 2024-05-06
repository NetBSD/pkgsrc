# $NetBSD: Makefile,v 1.10 2024/05/06 08:40:23 jperkin Exp $

DISTNAME=	git-branchless-0.8.0
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arxanas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arxanas/git-branchless/
COMMENT=	High-velocity, monorepo-scale workflow for Git
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/ioctl-rs-0.1.6/src/os/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-branchless \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
