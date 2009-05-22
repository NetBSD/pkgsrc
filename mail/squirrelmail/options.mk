# $NetBSD: options.mk,v 1.9.4.3 2009/05/22 10:18:40 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squirrelmail
PKG_SUPPORTED_OPTIONS=	squirrelmail-japanese squirrelmail-lite

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		japanese
.if !empty(PKG_OPTIONS:Msquirrelmail-japanese)
PLIST.japanese=		yes
PATCHFILES+=		squirrelmail-1.4.19-ja-20090522-patch.gz
SITES.squirrelmail-1.4.19-ja-20090522-patch.gz= \
			http://www.yamaai-tech.com/~masato/Download/
PATCH_DIST_STRIP.squirrelmail-1.4.19-ja-20090522-patch.gz=	-p1
.endif

.if !empty(PKG_OPTIONS:Msquirrelmail-lite)
PATCHFILES+=		squirrelmail-1.4.18-lite-20090512-patch.bz2
SITES.squirrelmail-1.4.18-lite-20090512-patch.bz2= \
			ftp://ftp.back-street.net/pub/squirrelmail/

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.3:../../misc/php-mbstring
.endif
