# $NetBSD: Makefile,v 1.20 2026/05/22 08:19:34 pin Exp $

DISTNAME=	git-branchless-0.11.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arxanas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arxanas/git-branchless/
COMMENT=	High-velocity, monorepo-scale workflow for Git
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.86.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

SUBST_CLASSES+=			indexedlog-netbsd
SUBST_STAGE.indexedlog-netbsd=	pre-configure
SUBST_FILES.indexedlog-netbsd=	../vendor/sapling-indexedlog-0.1.0/Cargo.toml
SUBST_SED.indexedlog-netbsd=	-e 's|cfg(target_os = \\"linux\\")|cfg(any(target_os = \\"linux\\", target_os = \\"netbsd\\"))|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-branchless \
		${DESTDIR}${PREFIX}/bin

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
