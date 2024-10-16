# $NetBSD: Makefile,v 1.13 2024/10/16 10:02:34 pin Exp $

DISTNAME=	git-branchless-0.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arxanas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arxanas/git-branchless/
COMMENT=	High-velocity, monorepo-scale workflow for Git
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.74.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/ioctl-rs-0.1.6/src/os/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-branchless \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
