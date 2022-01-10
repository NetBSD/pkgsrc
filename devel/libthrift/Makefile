# $NetBSD: Makefile,v 1.91 2022/01/10 01:46:29 ryoon Exp $

PKGREVISION= 1
.include "../../devel/thrift/Makefile.common"

PKGNAME=	lib${DISTNAME}
COMMENT=	C++ bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/cpp

TOOLS_BROKEN+=	perl

CONFIGURE_ARGS+=	--without-rs # puts garbage into Makefile
CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift
CONFIGURE_ENV+=		ac_cv_prog_PERL= # none, not needed
PKGCONFIG_OVERRIDE=	lib/cpp/thrift-nb.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift-z.pc.in
PKGCONFIG_OVERRIDE+=	lib/cpp/thrift.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
