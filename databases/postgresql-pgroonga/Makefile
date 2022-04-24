# $NetBSD: Makefile,v 1.8 2022/04/24 17:43:21 tnn Exp $

DISTNAME=	pgroonga-2.3.6
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://packages.groonga.org/source/pgroonga/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pgroonga.github.io/
COMMENT=	Fast full text search for PostgreSQL for all languages
LICENSE=	postgresql-license

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

.include "../../textproc/groonga/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
