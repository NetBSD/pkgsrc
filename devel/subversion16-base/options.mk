# $NetBSD: options.mk,v 1.1 2013/02/09 13:28:34 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.subversion16
PKG_SUPPORTED_OPTIONS=	apr1 serf sasl
.include "../../mk/bsd.prefs.mk"
.if !defined(PKG_APACHE_DEFAULT) || empty(PKG_APACHE_DEFAULT:Mapache2)
PKG_SUGGESTED_OPTIONS=	apr1
.endif

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
