# $NetBSD: options.mk,v 1.1 2004/11/25 21:42:59 xtraeme Exp $
#
# XXX Support for the following variables will be removed after the
# XXX pkgsrc-2004Q4 branch is released:
# XXX
# XXX USE_OPENLDAP
# XXX USE_XFACE
# XXX XEMACS_ESD
# XXX XEMACS_USE_CANNA

.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ldap
.endif

.if defined(USE_XFACE) && !empty(USE_XFACE:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	xfaces
.endif

.if defined(XEMACS_USE_CANNA) && !empty(XEMACS_USE_CANNA:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	canna
.endif

.if defined(XEMACS_ESD) && !empty(XEMACS_ESD:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	esoundd
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.xemacs
PKG_SUPPORTED_OPTIONS=	esoundd ldap xface canna

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.else
CONFIGURE_ARGS=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mxface)
CONFIGURE_ARGS=	--with-xface
.  include "../../mail/faces/buildlink3.mk"
.else
CONFIGURE_ARGS=	--without-xface
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS=	--with-canna
.else
CONFIGURE_ARGS=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-sound=none
.endif

