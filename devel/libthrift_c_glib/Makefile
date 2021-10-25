# $NetBSD: Makefile,v 1.8 2021/10/25 16:49:36 adam Exp $

.include "../../devel/thrift/Makefile.common"

PKGNAME=	${DISTNAME:S/thrift/libthrift_c_glib/}
COMMENT=	C (Glib) bindings for the Apache Thrift RPC system

DEPENDS+=	thrift-[0-9]*:../../devel/thrift
BUILD_DIRS=	lib/c_glib

TOOLS_BROKEN+=		perl

CONFIGURE_ARGS+=	--without-rs # puts garbage into Makefile
CONFIGURE_ENV+=		THRIFT=${PREFIX}/bin/thrift
PKGCONFIG_OVERRIDE=	lib/c_glib/thrift_c_glib.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
