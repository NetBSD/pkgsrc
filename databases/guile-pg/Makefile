# $NetBSD: Makefile,v 1.1.1.1 2002/10/27 01:14:09 cjones Exp $
#

DISTNAME=	guile-pg-0.07
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=guile-pg/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://guile-pg.sourceforge.net/
COMMENT=	PostgreSQL interface for Guile

DEPENDS+=	postgresql-lib>=7:../../databases/postgresql-lib
DEPENDS+=	guile>=1.3:../../lang/guile

USE_LIBTOOL=	YES
USE_GMAKE=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-libpq-includes=${PREFIX}/include/pgsql

#INFO_FILES=	guile-pg.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
