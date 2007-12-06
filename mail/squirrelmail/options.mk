# $NetBSD: options.mk,v 1.5.2.1 2007/12/06 10:36:33 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.squirrelmail
PKG_SUPPORTED_OPTIONS=	squirrelmail-japanese squirrelmail-lite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msquirrelmail-japanese)
PATCHFILES+=		squirrelmail-1.4.12-ja-20071205-patch.gz
SITES.squirrelmail-1.4.12-ja-20071205-patch.gz= \
			http://www.yamaai-tech.com/~masato/Download/
PATCH_DIST_STRIP.squirrelmail-1.4.12-ja-20071205-patch.gz=	-p1

.endif

.if !empty(PKG_OPTIONS:Msquirrelmail-lite)
PATCHFILES+=		squirrelmail-1.4.11-lite-20071003-patch.bz2
SITES.squirrelmail-1.4.11-lite-20071003-patch.bz2= \
			ftp://ftp.back-street.net/pub/squirrelmail/

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.3:../../misc/php-mbstring
.endif
