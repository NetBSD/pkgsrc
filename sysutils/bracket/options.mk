# $NetBSD: options.mk,v 1.1 2023/06/04 11:00:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bracket
PKG_SUPPORTED_OPTIONS=	www
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwww)
USE_TOOLS+=	perl:run
DEPENDS+=	lighttpd-[0-9]*:../../www/lighttpd
.endif
