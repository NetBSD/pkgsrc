# $NetBSD: options.mk,v 1.8 2008/07/03 22:01:48 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.subversion
PKG_SUPPORTED_OPTIONS=	apache22 apr1 serf java sasl
PKG_SUGGESTED_OPTIONS=	apr1

# Note that this file is included as part of several packages.
# Therefore this file only defines options, but does not include the
# typical fragments to change behavior based on options, leaving those
# to the individual Makefiles.

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapache22) || !empty(PKG_OPTIONS:Mserf)
PKG_OPTIONS+=		apr1
.endif
