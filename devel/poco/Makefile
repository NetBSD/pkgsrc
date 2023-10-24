# $NetBSD: Makefile,v 1.15 2023/10/24 22:08:55 wiz Exp $

PKGNAME=	poco-${POCO_VERSION}
PKGREVISION=	4
CATEGORIES=	devel

COMMENT=	POCO C++ Foundation libraries

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
# XXX: this should delete in post-install ${DESTDIR}${PREFIX} instead
pre-install:
	${RM} -f ${WRKSRC}/Foundation/include/Poco/Platform.h.orig

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
