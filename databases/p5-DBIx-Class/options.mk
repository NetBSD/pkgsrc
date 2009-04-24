# $NetBSD: options.mk,v 1.1 2009/04/24 17:28:05 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-DBIx-Class
PKG_SUPPORTED_OPTIONS=	sql-translator

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msql-translator)
DEPENDS+=	p5-SQL-Translator>=0.09004:../../databases/p5-SQL-Translator
.endif
