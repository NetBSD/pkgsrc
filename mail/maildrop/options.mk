# $NetBSD: options.mk,v 1.1 2019/05/24 13:17:57 hauke Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.maildrop
PKG_SUPPORTED_OPTIONS=	authlib dovecot-auth dotlock flock
PKG_SUGGESTED_OPTIONS=	authlib flock

.include "../../mk/bsd.options.mk"

###
### Support using courier-authlib to look up mail account information.
###
.if !empty(PKG_OPTIONS:Mauthlib)
CONFIGURE_ARGS+=	--enable-authlib
.  include "../../security/courier-authlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

###
### Support using dovecot auth to look up mail account information.
###
.if !empty(PKG_OPTIONS:Mdovecot-auth)
CONFIGURE_ARGS+=	--enable-dovecotauth
.  include "../../mail/dovecot2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dovecotauth
.endif

###
### Select mailbox locking mechanism in accordance with other mail agents
###
.if !empty(PKG_OPTIONS:Mdotlock)
CONFIGURE_ARGS+=	--enable-use-dotlock=1
.else
CONFIGURE_ARGS+=	--enable-use-dotlock=0
.endif

# 'flock' stands for whatever configure finds most suitable on this
# machine from fcntl(2), lockf(3), flock(2)
.if !empty(PKG_OPTIONS:Mflock)
CONFIGURE_ARGS+=	--enable-use-flock=1
.else
CONFIGURE_ARGS+=	--enable-use-flock=0
.endif
