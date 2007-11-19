PKG_OPTIONS_VAR=		PKG_OPTIONS.cone
PKG_SUPPORTED_OPTIONS=		aspell ldap
PKG_SUGGESTED_OPTIONS=		aspell ldap

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
### LDAP addressbook support
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
