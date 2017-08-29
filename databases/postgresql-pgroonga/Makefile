# $NetBSD: Makefile,v 1.1 2017/08/29 13:38:23 fhajny Exp $

DISTNAME=	pgroonga-1.2.3
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://packages.groonga.org/source/pgroonga/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pgroonga.github.io/
COMMENT=	Fast full text search for PostgreSQL for all languages
LICENSE=	postgresql-license

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

PGSQL_VERSIONS_ACCEPTED=	96 95 94 93

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

.include "../../textproc/groonga/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
