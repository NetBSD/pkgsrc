# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:35 jlam Exp $
#

.include "../../databases/libpqxx/Makefile.common"

COMMENT=		C++ interface to postgresql-lib

NOT_FOR_PLATFORM=	NetBSD-*-pc532

USE_LANGUAGES=		c c++
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libpqxx.pc.in

GNU_CONFIGURE=		yes
PG_PREFIX=		${BUILDLINK_PREFIX.postgresql-lib}
CONFIGURE_ARGS+=	--with-postgres-lib=${PG_PREFIX}/lib
CONFIGURE_ARGS+=	--with-postgres-include=${PG_PREFIX}/include/postgresql

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
