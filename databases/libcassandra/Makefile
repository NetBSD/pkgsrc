# $NetBSD: Makefile,v 1.30 2016/03/05 11:28:11 jperkin Exp $
#

DISTNAME=		libcassandra-20101010
PKGREVISION=		20
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.ancient-solutions.com/pub/bsdprojects/NetBSD/packages/distfiles/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://github.com/posulliv/libcassandra/
LICENSE=		modified-bsd

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
CONFIGURE_ARGS+=	--disable-64bit
MAKE_ENV+=		AM_DEFAULT_VERBOSITY=1

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-c++11-extensions -Wno-error=unused-local-typedef
.endif

.include "../../mk/bsd.pkg.mk"
