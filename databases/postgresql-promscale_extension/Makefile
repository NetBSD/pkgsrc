# $NetBSD: Makefile,v 1.7 2021/08/24 18:26:28 tnn Exp $

DISTNAME=	promscale_extension-0.2.0
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	promscale_extension
GITHUB_TAG=	61d8d0fe39a424e380c7beb2da3755c3dd1bd359

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	timescale-extension-utils-rs-bc3bdd2f0e0bcd59c5d2a8fa23ae6cd0959e28bc.tar.gz
SITES.timescale-extension-utils-rs-bc3bdd2f0e0bcd59c5d2a8fa23ae6cd0959e28bc.tar.gz+=	-${MASTER_SITE_GITHUB:=timescale/}timescale-extension-utils-rs/archive/bc3bdd2f0e0bcd59c5d2a8fa23ae6cd0959e28bc.tar.gz

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
	mv ${WRKDIR}/*/timescale-extension-utils ${WRKSRC}
	mv ${WRKDIR}/*/postgres-headers-rs ${WRKSRC}

do-build: do-cargo-build
	cd ${WRKSRC} && ${BUILD_MAKE_CMD}

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
