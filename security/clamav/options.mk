# $NetBSD: options.mk,v 1.2 2013/10/02 18:30:13 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	milter clamav-experimental

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
.else
CONFIGURE_ARGS+=	--disable-milter
# XXX --disable-milter doesn't work as expected, so we need this
CONFIGURE_ENV+=		ac_cv_header_libmilter_mfapi_h=no
.endif

.if !empty(PKG_OPTIONS:Mclamav-experimental)
CONFIGURE_ARGS+=	--enable-experimental
.endif
