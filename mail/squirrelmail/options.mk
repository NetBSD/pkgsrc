# $NetBSD: options.mk,v 1.2 2007/05/22 11:13:27 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squirrelmail
PKG_SUPPORTED_OPTIONS=	squirrelmail-japanese squirrelmail-lite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msquirrelmail-japanese)
PATCH_SITES=		http://www.yamaai-tech.com/~masato/Download/
PATCHFILES=		squirrelmail-1.4.10a-ja-20070511-patch.gz
PATCH_DIST_STRIP=	-p1

.endif

.if !empty(PKG_OPTIONS:Msquirrelmail-lite)
PATCH_SITES+=		ftp://ftp.back-street.net/pub/squirrelmail/
PATCHFILES+=		squirrelmail-1.4.10a-lite-20070522-patch
.endif
