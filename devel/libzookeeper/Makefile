# $NetBSD: Makefile,v 1.1 2015/10/09 13:59:57 fhajny Exp $
#

.include "../../devel/zookeeper/Makefile.common"

PKGNAME=	lib${DISTNAME}
COMMENT=	Highly reliable distributed coordination C lib

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c99
USE_LIBTOOL=	yes

CONFIGURE_DIRS=	src/c

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LIBS.SunOS+=	-lnsl -lsocket

# Tests require c++ and cppunit
#USE_LANGUAGES+=	c++
#TEST_TARGET=	run-check

BUILDLINK_DEPMETHOD.cppunit=	build
.include "../../devel/cppunit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
