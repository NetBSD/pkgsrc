# $NetBSD: Makefile,v 1.20 2023/01/11 03:33:46 tnn Exp $

DISTNAME=	promscale_extension-0.8.0
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	promscale_extension
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/promscale_extension
COMMENT=	The Promscale extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

.include	"cargo-depends.mk"

PGSQL_VERSIONS_ACCEPTED=	15 14 13 12

USE_TOOLS+=	gmake bash pax pkg-config
BUILD_TARGET=	package
MAKE_FLAGS+=	PG_CONFIG=${PREFIX}/bin/pg_config
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

SUBST_CLASSES+=			include_dir
SUBST_STAGE.include_dir=	pre-configure
SUBST_MESSAGE.include_dir=	fixing include paths for bindgen
SUBST_FILES.include_dir+=	../vendor/pgx-pg-sys-*/build.rs
SUBST_VARS.include_dir+=	BUILDLINK_DIR

pre-build:
	ln -sf ${PREFIX}/bin/cargo ${TOOLS_DIR}/bin/cargo
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} cargo install --offline --path ../vendor/cargo-pgx-* cargo-pgx
# cargo pgx init (initdb) refuses to run as root
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} cargo pgx init --pg${PGSQL_VERSION}=${PREFIX}/bin/pg_config
	mkdir -p ${FAKEHOMEDIR}/.pgx
	printf '[configs]\npg${PGSQL_VERSION}="${PREFIX}/bin/pg_config"\n' > ${FAKEHOMEDIR}/.pgx/config.toml

# prevent cargo.mk from claiming do-build
do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

do-install:
	cd ${WRKSRC}/target/release/promscale-pg${PGSQL_VERSION} && pax -rw . ${DESTDIR}

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
