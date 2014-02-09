# $NetBSD: json.mk,v 1.6 2014/02/09 06:08:18 taca Exp $

# This file handles appropriate dependency to ruby-json pacakge.
#

# === Package-settable variables ===
#
# RUBY_JSON_REQD
#	Specify required version of ruby-json.
#
#	Default: (empty)
#
# RUBY_JSON_TYPE
#	Specify depending packages: ruby-json, ruby-json-pure or both.
#
#	Possible values: json, pure
#	Default: json
#

.if !defined(_RUBY_JSON_MK)
_RUBY_JSON_MK=	# defined

RUBY_JSON_TYPE?= json

.if empty(RUBY_JSON_REQD)
WARNINGS+= "[lang/ruby/json.mk] No needs to include ../../lang/ruby/json.mk"
.else # !empty(RUBY_JSON_REQD)

.include "../../lang/ruby/rubyversion.mk"

.  if empty(RUBY_JSON_VERSION)
_RUBY_JSON_REQD=	true
.  else

_RUBY_JSON_MAJOR=	${RUBY_JSON_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
_RUBY_JSON_MINOR=	${RUBY_JSON_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
_RUBY_JSON_TEENY=	${RUBY_JSON_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\3/}

_RUBY_JSON_REQD_MAJOR=	${RUBY_JSON_REQD:C/^([0-9]+).*/\1/}
_RUBY_JSON_REQD_MINOR=	\
	${RUBY_JSON_REQD:C/^${_RUBY_JSON_REQD_MAJOR}\.?//:C/^([0-9]+).*/\1/}
.    if empty(_RUBY_JSON_REQD_MINOR)
_RUBY_JSON_REQD_MINOR=	0
_RUBY_JSON_REQD_TEENY=	0
.    else
_RUBY_JSON_REQD_TEENY=	\
  ${RUBY_JSON_REQD:C/^${_RUBY_JSON_REQD_MAJOR}\.${_RUBY_JSON_REQD_MINOR}\.?//}
.    endif
.    if empty(_RUBY_JSON_REQD_TEENY)
_RUBY_JSON_REQD_TEENY=	0
.    endif

.    if ${_RUBY_JSON_REQD_MAJOR} > ${_RUBY_JSON_MAJOR}
_RUBY_JSON_REQD=	true
.    elif ${_RUBY_JSON_REQD_MAJOR} == ${_RUBY_JSON_MAJOR}
.      if ${_RUBY_JSON_REQD_MINOR} > ${_RUBY_JSON_MINOR}
_RUBY_JSON_REQD=	true
.      elif ${_RUBY_JSON_REQD_MINOR} == ${_RUBY_JSON_MINOR}
.        if ${_RUBY_JSON_REQD_TEENY} > ${_RUBY_JSON_TEENY}
_RUBY_JSON_REQD=	true
.        endif
.      endif
.    endif
.  endif # empty(RUBY_JSON_VERSION)

.  if !empty(_RUBY_JSON_REQD)
.    if ${RUBY_JSON_TYPE} == "json"
DEPENDS+= ${RUBY_PKGPREFIX}-json>=${RUBY_JSON_REQD}:../../textproc/ruby-json
.    elif ${RUBY_JSON_TYPE} == "pure"
DEPENDS+= ${RUBY_PKGPREFIX}-json-pure>=${RUBY_JSON_REQD}:../../textproc/ruby-json-pure
.    endif
.  endif

.endif # !empty(RUBY_JSON_REQD)

.endif
