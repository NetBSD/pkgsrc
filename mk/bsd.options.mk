# $NetBSD: bsd.options.mk,v 1.41 2005/06/09 18:44:26 jlam Exp $
#
# This Makefile fragment provides boilerplate code for standard naming
# conventions for handling per-package build options.
#
# Before including this file, the following variables can be defined:
#
#	PKG_SUPPORTED_OPTIONS
#		This is a list of build options supported by the package.
#		This variable should be set in a package Makefile.  E.g.,
#
#			PKG_SUPPORTED_OPTIONS=	kerberos ldap ssl
#
#	PKG_OPTIONS_VAR (must be defined)
#               The variable the user can set to enable or disable
#		options specifically for this package.
#
#	PKG_OPTIONS_OPTIONAL_GROUPS
#		This is a list names of groups of mutually exclusive
#		options.  The options in each group are listed in
#		PKG_OPTIONS_GROUP.<groupname>.  The most specific
#		setting of any option from the group takes precedence
#		over all other options in the group.  Options from
#		the groups will be automatically added to
#		PKG_SUPPORTED_OPTOINS.
#
#	PKG_OPTIONS_REQUIRED_GROUPS
#		Like PKG_OPTIONS_OPTIONAL_GROUPS, but building
#		the packages will fail if no option from the group
#		is selected.
#
#	PKG_SUGGESTED_OPTIONS (defaults to empty)
#		This is a list of build options which are enabled by default.
#
#	PKG_OPTIONS_LEGACY_VARS
#               This is a list of USE_VARIABLE:option pairs that
#		map legacy /etc/mk.conf variables to their option
#		counterparts.
#
#	PKG_OPTIONS_LEGACY_OPTS
#		This is a list of old-option:new-option pairs that
#		map options that have been renamed to their new
#		counterparts.
#
#	PKG_LEGACY_OPTIONS
#		A list of options implied by deprecated variables
#		used.  This can be used for cases that neither
#		PKG_OPTIONS_LEGACY_VARS nor PKG_OPTIONS_LEGACY_OPTS
#		can handle, e. g. when PKG_OPTIONS_VAR is renamed.
#
#	PKG_OPTIONS_DEPRECATED_WARNINGS
#		A list of warnings about deprecated variables or
#		options used, and what to use instead.
#
#       At least one of PKG_SUPPORTED_OPTIONS, PKG_OPTIONS_OPTIONAL_GROUPS,
#	and PKG_OPTIONS_REQUIRED_GROUPS must be defined.
#		
#
# Optionally, the user may define the following variables in /etc/mk.conf:
#
#	PKG_DEFAULT_OPTIONS
#               This variable can be used to override default
#		options for every package.  Options listed in this
#		variable will be enabled in every package that
#		supports them.  If you prefix an option with `-',
#		it will be disabled in every package.
#
#	${PKG_OPTIONS_VAR}
#		This variable can be used to override default
#		options and options listed in PKG_DEFAULT_OPTIONS.
#		The syntax is the same as PKG_DEFAULT_OPTIONS.
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
# PKG_OPTIONS_VAR=		PKG_OPTIONS.wibble
# PKG_SUPPORTED_OPTIONS=	wibble-foo ldap sasl
# PKG_OPTIONS_OPTIONAL_GROUPS=	database
# PKG_OPTIONS_GROUP.database=	mysql pgsql
# PKG_SUGGESTED_OPTIONS=	wibble-foo
# PKG_OPTIONS_LEGACY_VARS+=	WIBBLE_USE_OPENLDAP:ldap
# PKG_OPTIONS_LEGACY_VARS+=	WIBBLE_USE_SASL2:sasl
# PKG_OPTIONS_LEGACY_OPTS+=	foo:wibble-foo
#
# # this package was previously named wibble2
# .include "../../mk/bsd.prefs.mk"
#
# .if defined(PKG_OPTIONS.wibble2)
# PKG_LEGACY_OPTIONS+=	${PKG_OPTIONS.wibble2}
# PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable PKG_OPTIONS.wibble2 used, use "${PKG_OPTIONS_VAR:Q}" instead."
# .endif
#
# .include "../../mk/bsd.options.mk"
#
# # Package-specific option-handling
#
# ###
# ### FOO support
# ###
# .if !empty(PKG_OPTIONS:Mwibble-foo)
# CONFIGURE_ARGS+=	--enable-foo
# .endif

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
#
# ###
# ### database support
# ###
# .if !empty(PKG_OPTIONS:Mmysql)
# .  include "../../mk/mysql.buildlink3.mk"
# .endif
# .if !empty(PKG_OPTIONS:Mpgsql)
# .  include "../../mk/pgsql.buildlink3.mk"
# .endif
# -------------8<-------------8<-------------8<-------------8<-------------

.include "../../mk/bsd.prefs.mk"

# Define PKG_OPTIONS, no matter if we have an error or not, to suppress
# further make(1) warnings.
PKG_OPTIONS=		# empty

# Check for variable definitions required before including this file.
.if !defined(PKG_SUPPORTED_OPTIONS) && !defined(PKG_OPTIONS_OPTIONAL_GROUPS) && !defined(PKG_OPTIONS_REQUIRED_GROUPS)
PKG_FAIL_REASON+=	"bsd.options.mk: At least one of PKG_SUPPORTED_OPTIONS, PKG_OPTIONS_OPTIONAL_GROUPS, and PKG_OPTIONS_REQUIRED_GROUPS must be defined."
.elif !defined(PKG_OPTIONS_VAR)
PKG_FAIL_REASON+=	"bsd.options.mk: PKG_OPTIONS_VAR is not defined."
.else # process the rest of the file

#
# create map of option to group and add group options to PKG_SUPPORTED_OPTOINS
#
.for _grp_ in ${PKG_OPTIONS_OPTIONAL_GROUPS} ${PKG_OPTIONS_REQUIRED_GROUPS}
_PKG_OPTIONS_GROUP_STACK.${_grp_}:=#empty
.  for _opt_ in ${PKG_OPTIONS_GROUP.${_grp_}}
PKG_SUPPORTED_OPTIONS+= ${_opt_}
_PKG_OPTIONS_GROUP_MAP.${_opt_}=${_grp_}
.  endfor
.endfor

#
# include deprecated variable to options mapping
#
.include "${.CURDIR}/../../mk/defaults/obsolete.mk"

#
# place options imlied by legacy variables in PKG_LEGACY_OPTIONS
#
.for _m_ in ${PKG_OPTIONS_LEGACY_VARS}
_var_:=	${_m_:C/:.*//}
_opt_:=	${_m_:C/.*://}
_popt_:=${_opt_:C/^-//}
.  if !empty(PKG_SUPPORTED_OPTIONS:M${_popt_})
.    if defined(${_var_})
PKG_OPTIONS_DEPRECATED_WARNINGS:=${PKG_OPTIONS_DEPRECATED_WARNINGS} "Deprecated variable "${_var_:Q}" used, use PKG_DEFAULT_OPTIONS+="${_popt_:Q}" instead."
.      if empty(${_var_}:M[nN][oO])
PKG_LEGACY_OPTIONS:=${PKG_LEGACY_OPTIONS} ${_opt_}
.      elif empty(_opt_:M-*)
PKG_LEGACY_OPTIONS:=${PKG_LEGACY_OPTIONS} -${_popt_}
.      else
PKG_LEGACY_OPTIONS:=${PKG_LEGACY_OPTIONS} ${_popt_}
.      endif
.    endif
.  endif
.endfor
.undef _var_
.undef _opt_
.undef _popt_

#
# create map of old option name to new option name for legacy options
#
.for _m_ in ${PKG_OPTIONS_LEGACY_OPTS}
_old_:= ${_m_:C/:.*//}
_new_:= ${_m_:C/.*://}
.  if !empty(PKG_SUPPORTED_OPTIONS:M${_new_})
_PKG_LEGACY_OPTMAP.${_old_}:=${_new_}
PKG_OPTIONS_DEPRECATED_WARNINGS:=${PKG_OPTIONS_DEPRECATED_WARNINGS} "Deprecated option "${_old_:Q}" used, use option "${_new_:Q}" instead."
.  endif
.endfor
.undef _old_
.undef _new_

#
# filter unsupported options from PKG_DEFAULT_OPTIONS
#
_OPTIONS_DEFAULT_SUPPORTED:=	#empty
.for _o_ in ${PKG_DEFAULT_OPTIONS}
_opt_:=		${_o_}
_popt_:=	${_opt_:C/^-//}
.if !empty(PKG_SUPPORTED_OPTIONS:M${_popt_}) \
	|| defined(_PKG_LEGACY_OPTMAP.${_popt_})
_OPTIONS_DEFAULT_SUPPORTED:=${_OPTIONS_DEFAULT_SUPPORTED} ${_opt_}
.endif
.endfor
.undef _opt_
.undef _popt_

#
# process options from generic to specific
#
PKG_OPTIONS:=		# empty
_OPTIONS_UNSUPPORTED:=	#empty
.for _o_ in ${PKG_SUGGESTED_OPTIONS} ${PKG_LEGACY_OPTIONS} \
	${_OPTIONS_DEFAULT_SUPPORTED} ${${PKG_OPTIONS_VAR}}
_opt_:=		${_o_}
_popt_:=	${_o_:C/^-//}	# positive option
.  if defined(_PKG_LEGACY_OPTMAP.${_popt_})
_popt_:=	${_PKG_LEGACY_OPTMAP.${_popt_}}
.    if empty(_opt_:M-*)
_opt_:=		${_popt_}
.    else
_opt_:=		-${_popt_}
.    endif
.  endif
.  if empty(PKG_SUPPORTED_OPTIONS:M${_popt_})
_OPTIONS_UNSUPPORTED:=${_OPTIONS_UNSUPPORTED} ${_opt_}
.  else
.    if defined(_PKG_OPTIONS_GROUP_MAP.${_popt_})
_grp_:= ${_PKG_OPTIONS_GROUP_MAP.${_popt_}}
_stk_:=	_PKG_OPTIONS_GROUP_STACK.${_grp_}
_cnt_:=	${${_stk_}}
.      if !empty(_opt_:M-*)
${_stk_}:=	${_cnt_:N${_popt_}}
.      else
${_stk_}:=	${_cnt_} ${_popt_}
.      endif
.    else
.      if !empty(_opt_:M-*)
PKG_OPTIONS:=	${PKG_OPTIONS:N${_popt_}}
.      else
PKG_OPTIONS:=	${PKG_OPTIONS} ${_popt_}
.      endif
.    endif
.  endif
.endfor
.undef _opt_
.undef _popt_
.undef _stk_

.for _grp_ in ${PKG_OPTIONS_REQUIRED_GROUPS}
.  if empty(_PKG_OPTIONS_GROUP_STACK.${_grp_})
PKG_FAIL_REASON:="One of the following options must be selected: "${PKG_OPTIONS_GROUP.${_grp_}:O:u:Q}
.  endif
.endfor

.for _grp_ in ${PKG_OPTIONS_REQUIRED_GROUPS} ${PKG_OPTIONS_OPTIONAL_GROUPS}
.undef _opt_
.  for _o_ in ${_PKG_OPTIONS_GROUP_STACK.${_grp_}}
_opt_:=		${_o_}
.  endfor
.  if defined(_opt_)
PKG_OPTIONS:=	${PKG_OPTIONS} ${_opt_}
.  endif
.endfor
.undef _opt_

.if !empty(_OPTIONS_UNSUPPORTED)
PKG_FAIL_REASON:=	"The following selected options are not supported: "${_OPTIONS_UNSUPPORTED:O:u:Q}"."
.endif

.undef _OPTIONS_UNSUPPORTED
.undef _OPTIONS_DEFAULT_SUPPORTED
PKG_OPTIONS:=	${PKG_OPTIONS:O:u}

_PKG_OPTIONS_WORDWRAP_FILTER=						\
	${AWK} '							\
		BEGIN { printwidth = 40; line = "" }			\
		{							\
			if (length(line) > 0)				\
				line = line" "$$0;			\
			else						\
				line = $$0;				\
			if (length(line) > 40) {			\
				print "	"line;				\
				line = "";				\
			}						\
		}							\
		END { if (length(line) > 0) print "	"line }		\
	'

.PHONY: show-options
show-options:
	@${ECHO} The following options are supported by this package:
.for _opt_ in ${PKG_SUPPORTED_OPTIONS:O}
.  if !defined(_PKG_OPTIONS_GROUP_MAP.${_opt_})
	@${ECHO} "	"${_opt_:Q}"	"`${SED} -n "s/^"${_opt_:Q}"	//p" ../../mk/defaults/options.description`
.  endif
.endfor
.for _grp_ in ${PKG_OPTIONS_REQUIRED_GROUPS}
	@${ECHO} "Exactly one of the following "${_grp_:Q}" options is required:"
.  for _opt_ in ${PKG_OPTIONS_GROUP.${_grp_}:O}
	@${ECHO} "	"${_opt_:Q}"	"`${SED} -n "s/^"${_opt_:Q}"	//p" ../../mk/defaults/options.description`
.  endfor
.endfor
.for _grp_ in ${PKG_OPTIONS_OPTIONAL_GROUPS}
	@${ECHO} "At most one of the following "${_grp_:Q}" options may be selected:"
.  for _opt_ in ${PKG_OPTIONS_GROUP.${_grp_}:O}
	@${ECHO} "	"${_opt_:Q}"	"`${SED} -n "s/^"${_opt_:Q}"	//p" ../../mk/defaults/options.description`
.  endfor
.endfor
	@${ECHO}
	@${ECHO} "These options are enabled by default: "${PKG_SUGGESTED_OPTIONS:O:Q}
	@${ECHO} "These options are currently enabled: "${PKG_OPTIONS:O:Q}

.if defined(PKG_SUPPORTED_OPTIONS)
.PHONY: supported-options-message
pre-install-depends: supported-options-message
supported-options-message:
.  if !empty(PKG_SUPPORTED_OPTIONS)
	@${ECHO} "=========================================================================="
	@${ECHO} "The supported build options for this package are:"
	@${ECHO} ""
	@${ECHO} ${PKG_SUPPORTED_OPTIONS:O:Q} | ${XARGS} -n 1 | ${_PKG_OPTIONS_WORDWRAP_FILTER}
.    if !empty(PKG_OPTIONS)
	@${ECHO} ""
	@${ECHO} "The currently selected options are:"
	@${ECHO} ""
	@${ECHO} ${PKG_OPTIONS:O:Q} | ${XARGS} -n 1 | ${_PKG_OPTIONS_WORDWRAP_FILTER}
.    endif
	@${ECHO} ""
	@${ECHO} "You can select which build options to use by setting PKG_DEFAULT_OPTIONS"
	@${ECHO} "or the following variable.  Its current value is shown:"
	@${ECHO} ""
.    if !defined(${PKG_OPTIONS_VAR})
	@${ECHO} "	${PKG_OPTIONS_VAR} (not defined)"
.    else
	@${ECHO} "	${PKG_OPTIONS_VAR} = ${${PKG_OPTIONS_VAR}}"
.    endif
.    if defined(PKG_OPTIONS_DEPRECATED_WARNINGS)
	@${ECHO}
	@for l in ${PKG_OPTIONS_DEPRECATED_WARNINGS}; \
	do \
		${ECHO} "$$l"; \
	done
.    endif
	@${ECHO} ""
	@${ECHO} "=========================================================================="
.  endif
.endif

.endif # defined(PKG_OPTIONS_VAR) && defined(PKG_SUPPORTED_OPTIONS)
