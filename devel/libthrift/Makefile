# $NetBSD: Makefile,v 1.77 2019/12/25 14:08:41 taca Exp $

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
