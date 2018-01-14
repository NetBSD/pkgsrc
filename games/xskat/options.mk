# $NetBSD: options.mk,v 1.2 2018/01/14 17:34:02 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xskat

PKG_SUPPORTED_OPTIONS=	altenburger_cards
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maltenburger_cards)
WITH_ALTENBURGER_CARDS=	1
.endif
