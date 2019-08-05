# $NetBSD: options.mk,v 1.6 2019/08/05 14:44:20 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	milter clamav-experimental unit-test

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	milter

.if !empty(PKG_OPTIONS:Mmilter)
# force use of pkgsrc version of libmilter -- clamav uses the sendmail binary
# to check API compatibility(!), so it must build with as new a version of
# libmilter as pkgsrc is capable of providing
USE_BUILTIN.libmilter=	no
.  include "../../mail/libmilter/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-milter
PLIST.milter=		yes
CONF_SAMPLES+=		clamav-milter.conf
SMF_INSTANCES+=		clamav-milter
.else
CONFIGURE_ARGS+=	--disable-milter
# XXX --disable-milter doesn't work as expected, so we need this
CONFIGURE_ENV+=		ac_cv_header_libmilter_mfapi_h=no
.endif

.if !empty(PKG_OPTIONS:Mclamav-experimental)
CONFIGURE_ARGS+=	--enable-experimental
.endif

# Enable unit test
.if !empty(PKG_OPTIONS:Munit-test)
CONFIGURE_ARGS+=		--enable-check
TEST_TARGET=			check
# unit test's Makefile depends on gmake.
USE_TOOLS+=			gmake
BUILDLINK_DEPMETHOD.check=	build
.  include "../../devel/check/buildlink3.mk"
.endif
