# $NetBSD: options.mk,v 1.10 2009/06/02 15:34:44 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.subversion
PKG_SUPPORTED_OPTIONS=	apr1 serf sasl
PKG_SUGGESTED_OPTIONS=	apr1

# Note that this file is included as part of several packages.
# Therefore this file defines options and includes some but not all of
# the typical fragments, leaving some to individual package files.

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	serf neon

.if !empty(PKG_OPTIONS:Mserf)
DAV_RA=		serf
PLIST.serf=	yes
.  include "../../www/serf/buildlink3.mk"
.else
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
DAV_RA=		neon
PLIST.neon=	yes
.  include "../../www/neon/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.else
CONFIGURE_ARGS+=	--without-sasl
.endif
