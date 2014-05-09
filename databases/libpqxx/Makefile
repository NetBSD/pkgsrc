# $NetBSD: Makefile,v 1.28 2014/05/09 07:36:56 wiz Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 4.0.1

.include "../../databases/libpqxx/Makefile.common"

COMMENT=		C++ interface to postgresql-lib

NOT_FOR_PLATFORM=	NetBSD-*-pc532

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in
GNU_CONFIGURE=		yes

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+=	tools/splitconfig

.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
