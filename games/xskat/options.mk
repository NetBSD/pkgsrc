# $NetBSD: options.mk,v 1.1 2010/06/03 16:27:43 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xskat

PKG_SUPPORTED_OPTIONS=	altenburger_cards
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maltenburger_cards)
WITH_ALTENBURGER_CARDS=1
.endif
