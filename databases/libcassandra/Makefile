# $NetBSD: Makefile,v 1.9 2012/01/09 02:54:25 obache Exp $
#

DISTNAME=		libcassandra-20101010
PKGREVISION=		4
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.ancient-solutions.com/pub/bsdprojects/NetBSD/packages/distfiles/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://github.com/posulliv/libcassandra/
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

COMMENT=		C++ interface to Cassandra

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl

# libthrift is not clean
BUILDLINK_TRANSFORM+=	rm:-Wundef

.include "../../mk/bsd.prefs.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.if ${OPSYS} != "DragonFly"
.include "../../lang/gcc44/buildlink3.mk"
.endif

pre-configure:
.if ${OPSYS} != "DragonFly"
.include "../../lang/gcc44/preconfigure.mk"
.endif

CONFIGURE_ARGS+=	CPPFLAGS="-I${BUILDLINK_PREFIX.libthrift}/include/thrift -I${BUILDLINK_PREFIX.boost-headers}/include/boost"
MAKE_ENV+=		AM_DEFAULT_VERBOSITY=1

.include "../../mk/bsd.pkg.mk"
