# $NetBSD: Makefile,v 1.13 2022/04/18 19:10:39 adam Exp $

DISTNAME=	promscale_extension-0.3.2
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
PKGREVISION=	1
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

PGSQL_VERSIONS_ACCEPTED=	14 13 12
CARGO_FEATURES+=		pg${PGSQL_VERSION}

USE_TOOLS+=	gmake

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
