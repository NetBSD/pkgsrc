# $NetBSD: Makefile,v 1.4 2003/01/07 11:43:48 uebayasi Exp $
#

DISTNAME=	guile-pg-0.07
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=guile-pg/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://guile-pg.sourceforge.net/
COMMENT=	PostgreSQL interface for Guile

DEPENDS+=	postgresql-lib>=7.3.1:../../databases/postgresql-lib

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-libpq-includes=${BUILDLINK_DIR}/include/postgresql

#INFO_FILES=	guile-pg.info

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
