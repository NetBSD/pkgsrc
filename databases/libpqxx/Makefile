# $NetBSD: Makefile,v 1.1 2004/01/07 11:08:53 is Exp $
#

DISTNAME=		libpqxx-2.1.3
CATEGORIES=		databases
MASTER_SITES=		ftp://gborg.postgresql.org/pub/libpqxx/stable/

MAINTAINER=		is@netbsd.org
HOMEPAGE=		http://pqxx.tk/
COMMENT=		C++ interface to postgresql-lib

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libpqxx.pc.in

GNU_CONFIGURE=		yes
PG_PREFIX=		${BUILDLINK_PREFIX.postgresql-lib}
CONFIGURE_ARGS+=	--with-postgres-lib=${PG_PREFIX}/lib
CONFIGURE_ARGS+=	--with-postgres-include=${PG_PREFIX}/include/postgresql

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
