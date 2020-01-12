# $NetBSD: Makefile,v 1.78 2020/01/12 20:20:11 ryoon Exp $

PKGREVISION= 1
.include "../../devel/thrift/Makefile.common"

PKGNAME=	lib${DISTNAME}
COMMENT=	C++ bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/cpp

CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift
PKGCONFIG_OVERRIDE=	lib/cpp/thrift-nb.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift-z.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
