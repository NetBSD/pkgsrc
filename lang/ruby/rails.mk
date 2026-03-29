# $NetBSD: rails.mk,v 1.188 2026/03/29 14:26:36 taca Exp $

.if !defined(_RUBY_RAILS_MK)
_RUBY_RAILS_MK=	# defined

#
# === User-settable variables ===
#
# RUBY_RAILS_DEFAULT
#	Select default Ruby on Rails version.
#
#	Possible values: 61 72 80
#	Default: 72
#
#
# === Infrastructure variables ===
#
# RUBY_RAILS_REQD
#	Ruby Rails version to use. This variable should not be set in
#	packages.
#
#		Possible values: ${RUBY_RAILS_ACCEPTED}
#		Default:         ${RUBY_RAILS_DEFAULT}
#
# === Package-settable variables ===
#
# RUBY_RAILS_ACCEPTED
#	The Ruby on Rails versions that are acceptable for the package.
#
#	Possible values: 61 72 80
#	Default: (empty)
#
# RUBY_RAILS_STRICT_DEP
#	Strict dependency to Ruby on Rails component packages.
#
#	Possible value: yes no
#	Default: no
#
# === Defined variables ===
#
# RUBY_RAILS
#	Selected Ruby on Rails version.
#
#	Possible values: 61 72 80
#

#
# current Ruby on Rails versions.
#
RUBY_RAILS61_VERSION?=	6.1.7.10
RUBY_RAILS72_VERSION?=	7.2.3.1
RUBY_RAILS80_VERSION?=	8.0.4

RUBY_RAILS_ACCEPTED?=	# empty
RUBY_RAILS_DEFAULT?=	72

RUBY_RAILS_STRICT_DEP?=	no

RUBY_RAILS_SUPPORTED=	61 72 80

.if empty(RUBY_RAILS_SUPPORTED:M${RUBY_RAILS_DEFAULT})
.  error Unsupported RUBY_RAILS_DEFAULT: ${RUBY_RAILS_DEFAULT}
.endif

.if empty(RUBY_RAILS_ACCEPTED)
RUBY_RAILS_ACCEPTED=	${RUBY_RAILS_SUPPORTED}
.endif

.if defined(RUBY_RAILS_REQD)
.  if empty(RUBY_RAILS_ACCEPTED:M${RUBY_RAILS_REQD})
.    error Unsupported RUBY_RAILS_REQD: ${RUBY_RAILS_REQD}
.  endif
.  for rr in ${RUBY_RAILS_ACCEPTED}
.    if ${rr} == ${RUBY_RAILS_REQD}
RUBY_RAILS=	${rr}
.    endif
.  endfor
.endif

.if !defined(RUBY_RAILS)
.  for rr in ${RUBY_RAILS_ACCEPTED}
.    if ${rr} == ${RUBY_RAILS_DEFAULT}
RUBY_RAILS=	${rr}
.    else
RUBY_RAILS?=	${rr}
.    endif
.  endfor
.endif

RUBY_RAILS_REQD?=	${RUBY_RAILS}

.if ${RUBY_RAILS} == "80"
RAILS_VERSION:=	${RUBY_RAILS80_VERSION}
.elif ${RUBY_RAILS} == "72"
RAILS_VERSION:=	${RUBY_RAILS72_VERSION}
.elif ${RUBY_RAILS} == "61"
RAILS_VERSION:=	${RUBY_RAILS61_VERSION}
.endif

#
# Components of Ruby's version.
#
_RAILS_MAJOR=	${RAILS_VERSION:C/([0-9]+)\..*/\1/}
_RAILS_MINOR=	${RAILS_VERSION:C/([0-9]+)\.([0-9]+)\..*/\2/}
_RAILS_TEENY=	${RAILS_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+).*/\3/}

#
# If RUBY_RAILS_STRICT_DEP is defined, match exact current Ruby on Rails
# version. Otherwise allow greater minor version.
#

.if !empty(RUBY_RAILS_STRICT_DEP:M[yY][eE][sS])
_RAILS_NEXT_CMD=	${EXPR} ${_RAILS_TEENY} + 1
_RAILS_DEP= \
	${RUBY_RAILS}>=${RAILS_VERSION}<${_RAILS_MAJOR}.${_RAILS_MINOR}.${_RAILS_NEXT_CMD:sh}
.else
_RAILS_NEXT_CMD=	${EXPR} ${_RAILS_MINOR} + 1
_RAILS_DEP=	${RUBY_RAILS}>=${RAILS_VERSION}<${_RAILS_MAJOR}.${_RAILS_NEXT_CMD:sh}
.endif

#
MAKE_ENV+=	RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
		RUBY_RAILS_ACCEPTED=${RUBY_RAILS}
#
MULTI+=		RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
		RUBY_RAILS_ACCEPTED=${RUBY_RAILS}

PLIST_SUBST+=	RUBY_RAILS=${RUBY_RAILS}
FILES_SUBST+=	RUBY_RAILS=${RUBY_RAILS}

#
# Rails dependency supports
#
_RAILS_PKGS=	activesupport:devel activemodel:devel activejob:devel \
		activerecord:databases actionview:www actionpack:www \
		actioncable:www railties:devel activestorage:devel \
		actionmailer:mail actionmailbox:mail actiontext:textproc \
		rails:www

.for rp in ${_RAILS_PKGS}

RUBY_${rp:C/:.*$//:tu}_DEPENDS= \
	${RUBY_PKGPREFIX}-${rp:C/:.*$//}${_RAILS_DEP}:../../${rp:C/^.*://}/ruby-${rp:C/:.*$//}${RUBY_RAILS}

.endfor

.endif # _RUBY_RAILS_MK
