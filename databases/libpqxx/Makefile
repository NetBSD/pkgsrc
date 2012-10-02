# $NetBSD: Makefile,v 1.25 2012/10/02 21:25:21 asau Exp $
#

.include "../../databases/libpqxx/Makefile.common"

COMMENT=		C++ interface to postgresql-lib
PKGREVISION=		4

NOT_FOR_PLATFORM=	NetBSD-*-pc532

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# No strerror_r
CONFIGURE_ARGS+=	--disable-thread-safety
.endif

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
