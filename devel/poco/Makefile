# $NetBSD: Makefile,v 1.8 2013/11/29 12:54:55 joerg Exp $
#

PKGNAME=	poco-${POCO_VERSION}
PKGREVISION=	3
CATEGORIES=	devel

COMMENT=	POCO C++ Foundation libraries

# error: unable to open output file '.../poco-1.4.2p1-all/Foundation/obj/NetBSD/amd64/debug_shared/Ascii.o'
MAKE_JOBS_SAFE=	no

.include "../../devel/poco/Makefile.common"

CONFIGURE_ARGS+=	--library-path=${BUILDLINK_PREFIX.expat}/lib
CONFIGURE_ARGS+=	--library-path=${BUILDLINK_PREFIX.pcre}/lib
CONFIGURE_ARGS+=	--library-path=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--library-path=${BUILDLINK_PREFIX.openssl}/lib

CONFIGURE_ARGS+=	--include-path=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--include-path=${BUILDLINK_PREFIX.pcre}/include
CONFIGURE_ARGS+=	--include-path=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--include-path=${BUILDLINK_PREFIX.openssl}/include

# remove patch backup files.
pre-install:
	${RM} -f ${WRKSRC}/Foundation/include/Poco/Platform.h.orig

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
