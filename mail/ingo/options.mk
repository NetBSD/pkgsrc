# $NetBSD: options.mk,v 1.1.1.1 2006/03/31 22:06:34 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ingo
PKG_SUPPORTED_OPTIONS=	sieve imap

.include "../../mk/bsd.options.mk"

###
### Bring in support for the sieve filtering language
###
.if !empty(PKG_OPTIONS:Msieve)
DEPENDS+=	pear-Net_Sieve>=1.0.0:../../net/pear-Net_Sieve
.endif

###
### Bring in support for an IMAP server
###
.if !empty(PKG_OPTIONS:Mimap)
DEPENDS+=	php-imap>4.3.3:../../mail/php-imap
.endif
