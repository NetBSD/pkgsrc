# $NetBSD: Makefile,v 1.2 2020/11/03 23:05:49 tnn Exp $

DISTNAME=	promscale_extension-0.1.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	promscale_extension

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	timescale-extension-utils-rs-098962027183e1cd36acd6e1a47390f1cadbd33.tar.gz
SITES.timescale-extension-utils-rs-098962027183e1cd36acd6e1a47390f1cadbd33.tar.gz+=	-${MASTER_SITE_GITHUB:=timescale/}timescale-extension-utils-rs/archive/098962027183e1cd36acd6e1a47390f1caedbd33.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timescale/promscale_extension
COMMENT=	The Promscale extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server
.include	"cargo-depends.mk"

PGSQL_VERSIONS_ACCEPTED=	12 11

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
