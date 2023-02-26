# $NetBSD: options.mk,v 1.6 2023/02/26 20:39:49 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.alpine

PKG_SUPPORTED_OPTIONS+=	aspell ldap tcl
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
### Aspell spell-check support
###
.if !empty(PKG_OPTIONS:Maspell)
.  include "../../textproc/aspell/buildlink3.mk"
CONFIGURE_ARGS+=	--with-simple-spellcheck=aspell
CONFIGURE_ARGS+=	--with-interactive-spellcheck=aspell
CONFIGURE_ENV+=		ac_cv_path_alpine_simple_spellcheck=${PREFIX}/bin/aspell
CONFIGURE_ENV+=		ac_cv_path_alpine_interactive_spellcheck=${PREFIX}/bin/aspell
.endif

###
### LDAP server support
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
.else
CONFIGURE_ARGS+=    	--without-ldap
.endif

###
###  Web Alpine browser
###
.if !empty(PKG_OPTIONS:Mtcl)
.include "../../lang/tcl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tcl-lib-dir=${BUILDLINK_PREFIX.tcl}/lib
.else
CONFIGURE_ARGS+=	--without-tcl
.endif
