# $NetBSD: Makefile,v 1.9 2021/08/25 11:38:35 tnn Exp $

DISTNAME=	promscale_extension-0.2.0
PKGREVISION=	2
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	promscale_extension
GITHUB_TAG=	${PKGVERSION_NOREV}

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
PGX_TAG=	c82482493be32c7029498b057f22259e68675405
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	pgx-${PGX_TAG}.tar.gz
SITES.pgx-${PGX_TAG}.tar.gz+=	\
	-${MASTER_SITE_GITHUB:=JLockerman/}pgx/archive/${PGX_TAG}.tar.gz

CHECK_PORTABILITY_SKIP+=	pgx/*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/promscale_extension
COMMENT=	The Promscale extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server
.include	"cargo-depends.mk"

PGSQL_VERSIONS_ACCEPTED=	13 12
CARGO_FEATURES+=		pg${PGSQL_VERSION}

USE_TOOLS+=	gmake

post-extract:
	mv ${WRKDIR}/pgx-* ${WRKSRC}/pgx

do-configure:
	mkdir -p ${FAKEHOMEDIR}/.pgx
	printf '[configs]\npg${PGSQL_VERSION}="${PREFIX}/bin/pg_config"\n' > ${FAKEHOMEDIR}/.pgx/config.toml

do-build: do-cargo-build
	cd ${WRKSRC} && ${BUILD_MAKE_CMD}

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
