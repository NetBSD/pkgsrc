# $NetBSD: Makefile,v 1.9 2004/03/26 02:27:36 wiz Exp $
#

.include "../../databases/libpqxx/Makefile.common"

PKGREVISION=		1
COMMENT=		C++ interface to postgresql-lib

NOT_FOR_PLATFORM=	NetBSD-*-pc532

USE_LANGUAGES=		c c++
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in

GNU_CONFIGURE=		yes
PG_PREFIX=		${BUILDLINK_PREFIX.postgresql-lib}
CONFIGURE_ARGS+=	--with-postgres-lib=${PG_PREFIX}/lib
CONFIGURE_ARGS+=	--with-postgres-include=${PG_PREFIX}/include/postgresql

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
