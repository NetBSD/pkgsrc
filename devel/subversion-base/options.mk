# $NetBSD: options.mk,v 1.15 2020/03/30 11:44:10 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.subversion
PKG_SUPPORTED_OPTIONS=	serf sasl subversion-plaintext-storage
PKG_SUGGESTED_OPTIONS+=	serf

# Note that this file is included as part of several packages.
# Therefore this file defines options and includes some but not all of
# the typical fragments, leaving some to individual package files.

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	serf

.if !empty(PKG_OPTIONS:Mserf)
DAV_RA=		serf
PLIST.serf=	yes
BUILDLINK_ABI_DEPENDS.serf+=	serf>=1.2.1
.  include "../../www/serf/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.else
CONFIGURE_ARGS+=	--without-sasl
.endif

.if !empty(PKG_OPTIONS:Msubversion-plaintext-storage)
CONFIGURE_ARGS+=	--enable-plaintext-password-storage
.endif
