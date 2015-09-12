# $NetBSD: options.mk,v 1.12 2015/09/12 14:23:59 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_SUPPORTED_OPTIONS=	ldap sieve
PKG_SUGGESTED_OPTIONS=	sieve

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap sieve

###
### Sieve support
###
.if !empty(PKG_OPTIONS:Msieve)
.include "../../mail/libsieve/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sieve=${BUILDLINK_PREFIX.libsieve}
PLIST.sieve=		yes
FILES_SUBST+=		TIMSIEVED="dbmailtimsieved"
RCD_SCRIPTS+=		dbmailtimsieved
.else
FILES_SUBST+=		TIMSIEVED=""
.endif

###
### LDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.endif
