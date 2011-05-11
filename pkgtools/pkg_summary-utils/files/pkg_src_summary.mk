#####################################################################
.if defined(DIST_SUBDIR) && !empty(DIST_SUBDIR)
_ALLSRCFILES=    ${DISTFILES:@f@${DIST_SUBDIR}/${f}@} \
                 ${PATCHFILES:@f@${DIST_SUBDIR}/${f}@}
.else
_ALLSRCFILES=     ${_DISTFILES} ${_PATCHFILES}
.endif

ALLSRCFILES=     ${_ALLSRCFILES:O:u}

#####################################################################
# for multi-variant packages and bulk build software
.for i in ${_PBULK_MULTI} # apache php python ...
# Ex:
#   _VAR2DEFAULT.PKG_APACHE          = apache2
#   _VAR2DEFAULT.PYTHON_VERSION_REQD = 26
#   _VAR2DEFAULT.PHP_VERSION_REQD    = 5
_VAR2DEFAULT.${_PBULK_MULTI_VAR.${i}}=${${_PBULK_MULTI_DEFAULT.${i}}}
# Ex:
#   _VAR2ACCEPTEDVARNAME.PKG_APACHE           = PKG_APACHE_ACCEPTED
#   _VAR2ACCEPTEDVARNAME.PYTHON_VERSION_REQD  = _PYTHON_VERSIONS_ACCEPTED
#   _VAR2ACCEPTEDVARNAME.PHP_VERSION_REQD     = PHP_VERSIONS_ACCEPTED
_VAR2ACCEPTEDVARNAME.${_PBULK_MULTI_VAR.${i}}=${_PBULK_MULTI_LIST.${i}}
# Ex:
#   _VAR2ACCEPTEDVALUE.PKG_APACHE.13        = 1
#   _VAR2ACCEPTEDVALUE.PKG_APACHE.2         = 1
#   _VAR2ACCEPTEDVALUE.PKG_APACHE.22        = 1
.for j in ${${_PBULK_MULTI_LIST.${i}}}
_VAR2ACCEPTEDVALUE.${_PBULK_MULTI_VAR.${i}}.${j}=1
.endfor
.endfor

.for _SINGLE_ASSIGN in ${_ASSIGNMENTS:S/,/ /g}
_varname=			${_SINGLE_ASSIGN:C/=.*$//1}
_value=				${_SINGLE_ASSIGN:C/^[^=]*=//1}
# Ex:
#   _varname    = PYTHON_VERSION_REQD
#   _value      = 24
_VAR_ASSIGNED.${_varname}=	1
.if !defined(_VAR2DEFAULT.${_varname})
_ASSIGN2+=		${_SINGLE_ASSIGN}
.elif !defined(${_VAR2ACCEPTEDVARNAME.${_varname}})
__INHER_ASSIGNS_REJ+=	${_SINGLE_ASSIGN}
.elif !defined(_VAR2ACCEPTEDVALUE.${_varname}.${_value})
__INHER_ASSIGNS_BAD+=	${_SINGLE_ASSIGN}
.elif "${_VAR2DEFAULT.${_varname}}" != "${_value}"
_ASSIGN2+=		${_SINGLE_ASSIGN}
__INHER_ASSIGNS+=	${_SINGLE_ASSIGN}
.else
__INHER_ASSIGNS_REJ+=	${_SINGLE_ASSIGN}
.endif
.endfor

# ASSIGNMENTS contains everything included in _INHER_ASSIGNS and
# assignment to other variables, i.e. not PKG_APACHE,
# PYTHON_VERSION_REQD and PHP_VERSION_REQD.
ASSIGNMENTS=		${_ASSIGN2:ts,}

# _INHER_ASSIGNS contains variable assignments (PKG_APACHE,
# PYTHON_VERSION_REQD or PHP_VERSION_REQD) if their values are _not_
# equal to default values
_INHER_ASSIGNS=		${__INHER_ASSIGNS:ts,}

# _INHER_ASSIGNS_REJ contains variable assignments (PKG_APACHE,
# PYTHON_VERSION_REQD or PHP_VERSION_REQD) if their values
# are _equal_ to default values
_INHER_ASSIGNS_REJ=	${__INHER_ASSIGNS_REJ:ts,}

# _INHER_ASSIGNS_BAD contains variable assignments (PKG_APACHE,
# PYTHON_VERSION_REQD or PHP_VERSION_REQD) if they are not allowed, i.e.
# not listed in appropriate XXX_VERSIONS_ACCEPTED
_INHER_ASSIGNS_BAD=	${__INHER_ASSIGNS_BAD:ts,}

#####################################################################
# for multivariant packages

# Ex: 
#    PKGNAME=ap22-py26-python-3.3.1
#    PKGPATH=www/ap2-python
#    _VARIANTS=PKG_APACHE=apache2,apache22 PYTHON_VERSION_REQD=26,25,24
#    ...
.for i in ${_PBULK_MULTI}
.if defined(${_PBULK_MULTI_LIST.${i}}) && !defined(_VAR_ASSIGNED.${_PBULK_MULTI_VAR.${i}})
_VARIANTS+=	${_PBULK_MULTI_VAR.${i}}=${${_PBULK_MULTI_LIST.${i}}:ts,}
.endif
.endfor

#####################################################################
# pkg_src_summary -l
.ifdef with_libdeps
BUILD_DEPENDS+=	${_BLNK_ADD_TO.DEPENDS}
.endif

#####################################################################
.PHONY: my-show-vars
my-show-vars:
.for VARNAME in ${VARNAMES}
.if !empty(${VARNAME})
	@${ECHO} ${VARNAME}=${${VARNAME}:Q}
.endif
.endfor
