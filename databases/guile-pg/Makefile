# $NetBSD: Makefile,v 1.12 2004/02/14 17:21:35 jlam Exp $
#

DISTNAME=	guile-pg-0.07
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=guile-pg/}

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://guile-pg.sourceforge.net/
COMMENT=	PostgreSQL interface for Guile

DEPENDS+=	postgresql-lib>=7.3.1:../../databases/postgresql-lib

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-libpq-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql

INFO_FILES=	guile-pg.info

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
