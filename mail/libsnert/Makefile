# $NetBSD: Makefile,v 1.1.1.1 2003/10/27 17:56:58 manu Exp $
#

DISTNAME=		libsnert-1.23
CATEGORIES=		mail
MASTER_SITES=		http://www.snert.com/Software/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		manu@netbsd.org
HOMEPAGE=		http://www.snert.com/Software/download/
COMMENT=		Support library for milter-sender

WRKSRC=			${WRKDIR}/com/snert/src/lib
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mutex=flock
MAKEFILE=		makefile
USE_BUILDLINK2=		yes

INCDIR=			${WRKSRC}/../../include
LIBDIR=			${WRKSRC}/../../lib

do-install:
	${MKDIR} ${PREFIX}/include/com/snert/lib/crc
	${MKDIR} ${PREFIX}/include/com/snert/lib/io
	${MKDIR} ${PREFIX}/include/com/snert/lib/sys
	${MKDIR} ${PREFIX}/include/com/snert/lib/util
	${INSTALL_DATA} ${INCDIR}/com/snert/lib/autoconf.h	    \
			${PREFIX}/include/com/snert/lib/
	${INSTALL_DATA} ${INCDIR}/com/snert/lib/crc/Crc.h	    \
			${INCDIR}/com/snert/lib/crc/Luhn.h	    \
			${PREFIX}/include/com/snert/lib/crc
	${INSTALL_DATA} ${INCDIR}/com/snert/lib/io/Dns.h	    \
			${INCDIR}/com/snert/lib/io/Error.h	    \
			${INCDIR}/com/snert/lib/io/Log.h	    \
			${INCDIR}/com/snert/lib/io/Message.h	    \
			${INCDIR}/com/snert/lib/io/MessageStream.h  \
			${INCDIR}/com/snert/lib/io/posix.h	    \
			${INCDIR}/com/snert/lib/io/Socket.h	    \
			${INCDIR}/com/snert/lib/io/URI.h	    \
			${PREFIX}/include/com/snert/lib/io
	${INSTALL_DATA} ${INCDIR}/com/snert/lib/sys/Mutex.h	    \
			${INCDIR}/com/snert/lib/sys/Shared.h	    \
			${INCDIR}/com/snert/lib/sys/Thread.h	    \
			${INCDIR}/com/snert/lib/sys/Time.h 	    \
			${PREFIX}/include/com/snert/lib/sys
	${INSTALL_DATA} ${INCDIR}/com/snert/lib/util/BigInt.h	    \
			${INCDIR}/com/snert/lib/util/Buf.h	    \
			${INCDIR}/com/snert/lib/util/DebugMalloc.h  \
			${INCDIR}/com/snert/lib/util/EmailSpan.h    \
			${INCDIR}/com/snert/lib/util/getopt.h	    \
			${INCDIR}/com/snert/lib/util/HashTable.h    \
			${INCDIR}/com/snert/lib/util/JavaTime.h	    \
			${INCDIR}/com/snert/lib/util/md5.h	    \
			${INCDIR}/com/snert/lib/util/Memory.h	    \
			${INCDIR}/com/snert/lib/util/Pool.h	    \
			${INCDIR}/com/snert/lib/util/Property.h	    \
			${INCDIR}/com/snert/lib/util/Rotate.h	    \
			${INCDIR}/com/snert/lib/util/Text.h	    \
			${INCDIR}/com/snert/lib/util/Vector-new.h   \
			${INCDIR}/com/snert/lib/util/Vector.h	    \
			${PREFIX}/include/com/snert/lib/util
	${INSTALL_DATA} ${INCDIR}/com/snert/lib/version.h 	    \
			${PREFIX}/include/com/snert/lib
	${INSTALL_DATA} ${LIBDIR}/libsnert.a ${PREFIX}/lib

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
