# $NetBSD: Makefile,v 1.13 2012/08/29 11:22:10 obache Exp $
#

DISTNAME=		libcassandra-20101010
PKGREVISION=		7
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

.if ${OPSYS} != "DragonFly"
GCC_REQD+=	4.4
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"

CONFIGURE_ARGS+=	CPPFLAGS="-I${BUILDLINK_PREFIX.libthrift}/include/thrift -I${BUILDLINK_PREFIX.boost-headers}/include/boost"
MAKE_ENV+=		AM_DEFAULT_VERBOSITY=1

.include "../../mk/bsd.pkg.mk"
