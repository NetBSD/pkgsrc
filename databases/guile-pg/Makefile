# $NetBSD: Makefile,v 1.17 2004/10/03 00:13:18 tv Exp $
#

DISTNAME=	guile-pg-0.07
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=guile-pg/}

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://guile-pg.sourceforge.net/
COMMENT=	PostgreSQL interface for Guile

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-libpq-includes=${PGSQL_PREFIX}/include/postgresql

INFO_FILES=	guile-pg.info

PGSQL_VERSION_REQD=	73

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
