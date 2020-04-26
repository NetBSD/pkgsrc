# $NetBSD: Makefile,v 1.80 2020/04/26 09:57:24 rillig Exp $

PKGREVISION= 2
.include "../../devel/thrift/Makefile.common"

PKGNAME=	lib${DISTNAME}
COMMENT=	C++ bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/cpp

CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift
PKGCONFIG_OVERRIDE=	lib/cpp/thrift-nb.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift-z.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift.pc.in
TOOLS_BROKEN+=		perl # suppress warning about USE_TOOLS+=perl

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
