# $NetBSD: Makefile,v 1.3 2003/01/07 03:56:19 uebayasi Exp $
#

DISTNAME=	guile-pg-0.07
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=guile-pg/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://guile-pg.sourceforge.net/
COMMENT=	PostgreSQL interface for Guile

DEPENDS+=	postgresql-lib>=7.3.1:../../databases/postgresql-lib

USE_LIBTOOL=	YES
USE_GMAKE=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-libpq-includes=${PREFIX}/include/postgresql

#INFO_FILES=	guile-pg.info

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
