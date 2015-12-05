# $NetBSD: Makefile,v 1.30 2015/12/05 21:25:31 adam Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 4.0.1

.include "../../databases/libpqxx/Makefile.common"

COMMENT=		C++ interface to postgresql-lib

# Apparently (at least as of 2004) this package's shared libraries are
# messed up on a.out platforms. But AFAIK we don't have any in pkgsrc
# any more. Leave this here for documentation just in case.
#   - dholland 20150101
#NOT_FOR_PLATFORM=	${AOUTPLATFORMS}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpqxx.pc.in
GNU_CONFIGURE=		yes

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+=	tools/splitconfig

.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
