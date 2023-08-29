# $NetBSD: options.mk,v 1.9 2023/08/29 14:43:01 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	clamav-milter clamav-experimental clamav-unit-test

PKG_OPTIONS_LEGACY_OPTS+=	unit-test:clamav-unit-test
PKG_OPTIONS_LEGACY_OPTS+=	milter:clamav-milter

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	milter

.if ${PKG_OPTIONS:Mclamav-milter}
# force use of pkgsrc version of libmilter -- clamav uses the sendmail binary
# to check API compatibility(!), so it must build with as new a version of
# libmilter as pkgsrc is capable of providing
USE_BUILTIN.libmilter=	no
.  include "../../mail/libmilter/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-milter
PLIST.milter=		yes
CONF_SAMPLES+=		clamav-milter.conf
SMF_INSTANCES+=		clamav-milter
RCD_SCRIPTS+=		clamav-milter
.else
CONFIGURE_ARGS+=	--disable-milter
# XXX --disable-milter doesn't work as expected, so we need this
CONFIGURE_ENV+=		ac_cv_header_libmilter_mfapi_h=no
.endif

.if ${PKG_OPTIONS:Mclamav-experimental}
CONFIGURE_ARGS+=	--enable-experimental
.endif

# Enable unit test
.if ${PKG_OPTIONS:Mclamav-unit-test}
CONFIGURE_ARGS+=		--enable-check
TEST_TARGET=			check
# unit test's Makefile depends on gmake.
USE_TOOLS+=			gmake
BUILDLINK_DEPMETHOD.check=	build
.  include "../../devel/check/buildlink3.mk"
.endif
