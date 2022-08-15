# $NetBSD: Makefile,v 1.9 2022/08/15 22:17:24 tnn Exp $

DISTNAME=	pgroonga-2.3.6
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://packages.groonga.org/source/pgroonga/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pgroonga.github.io/
COMMENT=	Fast full text search for PostgreSQL for all languages
LICENSE=	postgresql-license

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

PGSQL_VERSIONS_ACCEPTED=	14 13 12 11

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

.include "../../textproc/groonga/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
