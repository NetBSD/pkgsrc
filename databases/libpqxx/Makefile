# $NetBSD: Makefile,v 1.12 2004/08/13 09:03:40 recht Exp $
#

.include "../../databases/libpqxx/Makefile.common"

PKGREVISION=		1
COMMENT=		C++ interface to postgresql-lib

NOT_FOR_PLATFORM=	NetBSD-*-pc532

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-postgres-lib=${PGSQL_PREFIX}/lib
CONFIGURE_ARGS+=	--with-postgres-include=${PGSQL_PREFIX}/include/postgresql

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

PGSQL_VERSION_REQD=	73

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
