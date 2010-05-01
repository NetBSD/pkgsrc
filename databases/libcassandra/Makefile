# $NetBSD: Makefile,v 1.1.1.1 2010/05/01 15:09:44 tonnerre Exp $
#

DISTNAME=		libcassandra-20100501
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.ancient-solutions.com/pub/bsdprojects/NetBSD/packages/distfiles/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://github.com/posulliv/libcassandra/

PKG_DESTDIR_SUPPORT=	user-destdir

COMMENT=		C++ interface to Cassandra

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	CPPFLAGS="-I${BUILDLINK_PREFIX.libthrift:Q}/include/thrift -I${BUILDLINK_PREFIX.boost-headers}/include/boost"
MAKE_ENV+=		AM_DEFAULT_VERBOSITY=1

.include "../../mk/bsd.pkg.mk"
