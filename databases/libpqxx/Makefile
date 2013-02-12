# $NetBSD: Makefile,v 1.26 2013/02/12 04:35:24 hiramatsu Exp $
#

.include "../../databases/libpqxx/Makefile.common"

COMMENT=		C++ interface to postgresql-lib

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

PYTHON_FOR_BUILD_ONLY=  yes
REPLACE_PYTHON+=	tools/splitconfig

.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
