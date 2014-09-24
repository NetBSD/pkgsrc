# $NetBSD: options.mk,v 1.1 2014/09/24 01:06:26 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mantis
PKG_SUPPORTED_OPTIONS=	charts
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcharts)
DEPENDS+=	${PHP_PKG_PREFIX}-jpgraph-[0-9]*:../../graphics/php-jpgraph
.endif
