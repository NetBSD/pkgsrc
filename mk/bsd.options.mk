# $NetBSD: bsd.options.mk,v 1.1 2004/07/30 20:59:08 jlam Exp $
#
# This Makefile fragment provides boilerplate code for standard naming
# conventions for handling per-package build options.
#
# Before including this file, the following variables should be defined:
#
#	PKG_OPTIONS_VAR
#		This is a list of the name of the make(1) variables that
#		contain the options the user wishes to select.  This
#		variable should be set in a package Makefile.  E.g.,
#
#			PKG_OPTIONS_VAR=	WIBBLE_OPTIONS
#		or
#			PKG_OPTIONS_VAR=	FOO_OPTIONS BAR_OPTIONS
#
#	PKG_SUPPORTED_OPTIONS
#		This is a list of build options supported by the package.
#		This variable should be set in a package Makefile.  E.g.,
#
#			PKG_SUPPORTED_OPTIONS=	kerberos ldap ssl
#
# Optionally, the following variables may also be defined:
#
#	PKG_DEFAULT_OPTIONS
#		This is a list the options that should be built into
#		every package, if that option is supported.  This
#		variable should be set in /etc/mk.conf.
#
#	${PKG_OPTIONS_VAR} (the variables named in PKG_OPTIONS_VAR)
#		These variables list the selected build options and
#		override any default options given in PKG_DEFAULT_OPTIONS.
#		If any of the options begin with a '-', then that option
#		is always removed from the selected build options, e.g.
#
#			PKG_DEFAULT_OPTIONS=	kerberos ldap sasl
#			PKG_OPTIONS_VAR=	WIBBLE_OPTIONS
#			WIBBLE_OPTIONS=		${PKG_DEFAULT_OPTIONS} -sasl
#			# implies PKG_OPTIONS == "kerberos ldap"
#		or
#			PKG_OPTIONS_VAR=	WIBBLE_OPTIONS
#			WIBBLE_OPTIONS=		kerberos -ldap ldap
#			# implies PKG_OPTIONS == "kerberos"
#
#		This variable should be set in /etc/mk.conf.
#
#	PKG_FAIL_UNSUPPORTED_OPTIONS
#		If this is set to "yes", then the presence of unsupported
#		options in PKG_OPTIONS.<pkg> (see below) causes the build
#		to fail.  Set this to "no" to silently ignore unsupported
#		options.  Default: "yes".
#
# After including this file, the following variables are defined:
#
#	PKG_OPTIONS
#		This is the list of the selected build options, properly
#		filtered to remove unsupported and duplicate options.
#
# Example usage:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# # Global and legacy options
# .if defined(USE_OPENLDAP) || defined(USE_SASL2)
# .  if !defined(PKG_OPTIONS.wibble)
# .    if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
# PKG_OPTIONS.wibble+=	ldap
# .    endif
# .    if defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
# PKG_OPTIONS.wibble+=	sasl
# .    endif
# .  endif
# .endif
#
# PKG_OPTIONS_VAR=		PKG_OPTIONS.wibble
# PKG_SUPPORTED_OPTIONS=	ldap sasl
# .include "../../mk/bsd.options.mk"
#
# # Package-specific option-handling
#
# ###
# ### LDAP support
# ###
# .if !empty(PKG_OPTIONS:Mldap)
# .  include "../../databases/openldap/buildlink3.mk"
# CONFIGURE_ARGS+=	--enable-ldap=${BUILDLINK_PREFIX.openldap}
# .endif
#
# ###
# ### SASL authentication
# ###
# .if !empty(PKG_OPTIONS:Msasl)
# .  include "../../security/cyrus-sasl2/buildlink3.mk"
# CONFIGURE_ARGS+=	--enable-sasl=${BUILDLINK_PREFIX.sasl}
# .endif
# -------------8<-------------8<-------------8<-------------8<-------------

.include "../../mk/bsd.prefs.mk"

# Check for variable definitions required before including this file.
.if !defined(PKG_SUPPORTED_OPTIONS)
PKG_FAIL_REASON+=	"bsd.options.mk: PKG_SUPPORTED_OPTIONS is not defined."
.endif
.if !defined(PKG_OPTIONS_VAR)
PKG_FAIL_REASON+=	"bsd.options.mk: PKG_OPTIONS_VAR is not defined."
.endif

# If none of the variables listed in PKG_OPTIONS_VAR is defined, then use
# the global options provided in ${PKG_DEFAULT_OPTIONS}.
#
_PKG_DEFAULT_OPTIONS=	# empty
.for _opt_ in ${PKG_DEFAULT_OPTIONS}
.  if !empty(PKG_SUPPORTED_OPTIONS:M${_opt_})
_PKG_DEFAULT_OPTIONS+=	${_opt_}
.  endif
.endfor
.undef _opt_
_PKG_OPTIONS_VAR=	# empty
.for _var_ in ${PKG_OPTIONS_VAR}
.  if defined(${_var_})
_PKG_OPTIONS_VAR+=	${_var_}
.  endif
.endfor
.undef _var_
.if empty(_PKG_OPTIONS_VAR)
_PKG_OPTIONS_VAR=	_PKG_DEFAULT_OPTIONS
.endif

# If this is set to "yes", then the presence of unsupported options in
# the variable named by ${PKG_OPTIONS_VAR} causes the build to fail.  Set
# this to "no" to silently ignore unsupported options.
#
PKG_FAIL_UNSUPPORTED_OPTIONS?=	yes

# Separate out the selected options into "positive" and "negative" lists.
_PKG_YES_OPTIONS=	# contains the "positive" options
.for _var_ in ${_PKG_OPTIONS_VAR}
_PKG_YES_OPTIONS+=	${${_var_}:N-*}
.endfor
_PKG_NO_OPTIONS=	# contains the "negative" options
.for _var_ in ${_PKG_OPTIONS_VAR}
_PKG_NO_OPTIONS+=	${${_var_}:M-*:S/^-//}
.endfor
.undef _var_

# Filter out unsupported and duplicate build options and store the result
# in PKG_OPTIONS.  We keep all of the "positive" options first, then remove
# all of the "negative" options last, so "negative" options always have
# the strongest effect.
#
PKG_OPTIONS=		# empty
.for _opt_ in ${_PKG_YES_OPTIONS}
.  if empty(_PKG_NO_OPTIONS:M${_opt_}) && empty(PKG_OPTIONS:M${_opt_})
.    if !empty(PKG_SUPPORTED_OPTIONS:M${_opt_})
PKG_OPTIONS+=		${_opt_}
.    elif !empty(PKG_FAIL_UNSUPPORTED_OPTIONS:M[yY][eE][sS])
PKG_FAIL_REASON+=	"\"${_opt_}\" is not a supported build option."
.    endif
.  endif
.endfor

# Store the result in the +BUILD_INFO file so we can query for the build
# options using "pkg_info -Q PKG_OPTIONS <pkg>".
#
BUILD_DEFS+=		PKG_OPTIONS
