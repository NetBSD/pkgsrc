# $NetBSD: options.mk,v 1.3 2006/08/10 14:33:06 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ingo
PKG_SUPPORTED_OPTIONS=	sieve imap ftp

.include "../../mk/bsd.options.mk"

###
### Bring in support for the sieve filtering language
###
.if !empty(PKG_OPTIONS:Msieve)
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Sieve>=1.0.0:../../net/pear-Net_Sieve
.endif

###
### Bring in support for an IMAP server
###
.if !empty(PKG_OPTIONS:Mimap)
DEPENDS+=	${PHP_PKG_PREFIX}-imap>4.3.3:../../mail/php-imap
.endif

###
### procmail or dropmail support need the PHP FTP extension
###
.if !empty((PKG_OPTIONS:Mftp)
DEPENDS+=	${PHP_PKG_PREFIX}-ftp>4.3.3:../../net/php-ftp
.endif
