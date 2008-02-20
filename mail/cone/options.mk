# $NetBSD: options.mk,v 1.5 2008/02/20 22:31:06 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.cone
PKG_SUPPORTED_OPTIONS=		aspell ldap
PKG_OPTIONS_REQUIRED_GROUPS=	display tls
PKG_OPTIONS_GROUP.display=	curses wide-curses
PKG_OPTIONS_GROUP.tls=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		aspell curses ldap ssl

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

###
### Aspell spell-check support
###
.if !empty(PKG_OPTIONS:Maspell)
.  include "../../textproc/aspell/buildlink3.mk"
CONFIGURE_ARGS+=	--with-spellcheck=aspell
.endif

###
### Curses display
###
.if !empty(PKG_OPTIONS:Mcurses)
USE_NCURSES=	yes	# termattrs()
.  include "../../devel/ncurses/buildlink3.mk"
.endif

###
### FAM (file alteration monitor) support
###
.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif

###
### GNU TLS support
###
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls
.endif

###
### LDAP addressbook support
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

###
### OpenSSL TLS support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

###
### Wide curses display
###
.if !empty(PKG_OPTIONS:Mwide-curses)
USE_NCURSESW=	yes	# termattrs()
.  include "../../devel/ncursesw/buildlink3.mk"
.endif
