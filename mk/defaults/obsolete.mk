# $NetBSD: obsolete.mk,v 1.27 2006/04/07 00:29:52 reed Exp $
#
# This file holds make(1) logic to allow obsolete or deprecated variables
# still to be used.  These may eventually disappear over time as the contents
# are, by definition, obsolete and deprecated.

.if defined(PRIV_CONF_DIR)
PKG_SYSCONFDIR.priv?=	${PRIV_CONF_DIR}
.endif

###
### Set PKG_LEGACY_OPTIONS based on to-be-deprecated global variables.
###

.if defined(KERBEROS)
.  if ${KERBEROS} == "4" && !empty(PKG_SUPPORTED_OPTIONS:Mkerberos4)
PKG_LEGACY_OPTIONS+=	kerberos4
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable KERBEROS used, use PKG_DEFAULT_OPTIONS+=kerberos4 instead."
.  elif !empty(PKG_SUPPORTED_OPTIONS:Mkerberos)
PKG_LEGACY_OPTIONS+=	kerberos
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable KERBEROS used, use PKG_DEFAULT_OPTIONS+=kerberos instead."
.  endif
.endif

PKG_OPTIONS_LEGACY_VARS+=	USE_INET6:inet6

#
# IGNORE_RECOMMENDED is deprecated and will be removed after 2006Q2 branch.
#
.if defined(IGNORE_RECOMMENDED) && !empty(IGNORE_RECOMMENDED:M[yY][eE][sS])
USE_ABI_DEPENDS=	no
.endif
