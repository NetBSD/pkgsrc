# $NetBSD: options.mk,v 1.2 2005/06/22 13:14:50 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.argus
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+= fping6-[0-9]*:../../net/fping6
DEPENDS+= p5-Socket6>=0.12:../../net/p5-Socket6
.endif
