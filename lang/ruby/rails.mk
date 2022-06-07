# $NetBSD: rails.mk,v 1.126 2022/06/07 14:59:20 taca Exp $

.if !defined(_RUBY_RAILS_MK)
_RUBY_RAILS_MK=	# defined

#
# === User-settable variables ===
#
# RUBY_RAILS_DEFAULT
#	Select default Ruby on Rails version.
#
#	Possible values: 52 60 61 70
#	Default: 52
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
#	Possible values: 52 60 61 70
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
#	Possible values: 52 60 61 70
#

#
# current Ruby on Rails versions.
#
RUBY_RAILS52_VERSION?=	5.2.8
RUBY_RAILS60_VERSION?=	6.0.5
RUBY_RAILS61_VERSION?=	6.1.5.1
RUBY_RAILS70_VERSION?=	7.0.2.4

RUBY_RAILS_ACCEPTED?=	# empty
RUBY_RAILS_DEFAULT?=	52

RUBY_RAILS_STRICT_DEP?=	no

RUBY_RAILS_SUPPORTED=	52 60 61 70

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

.if ${RUBY_RAILS} == "70"
RAILS_VERSION:=	${RUBY_RAILS70_VERSION}
.elif ${RUBY_RAILS} == "61"
RAILS_VERSION:=	${RUBY_RAILS61_VERSION}
.elif ${RUBY_RAILS} == "60"
RAILS_VERSION:=	${RUBY_RAILS60_VERSION}
.elif ${RUBY_RAILS} == "52"
RAILS_VERSION:=	${RUBY_RAILS52_VERSION}
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
_RAILS_NEXT!=	${EXPR} ${_RAILS_TEENY} + 1
_RAILS_DEP=	\
	${RUBY_RAILS}>=${RAILS_VERSION}<${_RAILS_MAJOR}.${_RAILS_MINOR}.${_RAILS_NEXT}
.else
_RAILS_NEXT!=	${EXPR} ${_RAILS_MINOR} + 1
_RAILS_DEP=	${RUBY_RAILS}>=${RAILS_VERSION}<${_RAILS_MAJOR}.${_RAILS_NEXT}
.endif

#
MAKE_ENV+=	RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
		RUBY_RAILS_ACCEPTED=${RUBY_RAILS}
#
MULTI+=		RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
		RUBY_RAILS_ACCEPTED=${RUBY_RAILS}

PLIST_SUBST+=	RUBY_RAILS=${RUBY_RAILS}
FILES_SUBST+=	RUBY_RAILS=${RUBY_RAILS}

RUBY_ACTIVESUPPORT_DEPENDS= \
	${RUBY_PKGPREFIX}-activesupport${_RAILS_DEP}:../../devel/ruby-activesupport${RUBY_RAILS}
RUBY_ACTIVEMODEL_DEPENDS= \
	${RUBY_PKGPREFIX}-activemodel${_RAILS_DEP}:../../devel/ruby-activemodel${RUBY_RAILS}
RUBY_ACTIONPACK_DEPENDS= \
	${RUBY_PKGPREFIX}-actionpack${_RAILS_DEP}:../../www/ruby-actionpack${RUBY_RAILS}
RUBY_ACTIVERECORD_DEPENDS= \
	${RUBY_PKGPREFIX}-activerecord${_RAILS_DEP}:../../databases/ruby-activerecord${RUBY_RAILS}
RUBY_ACTIONMAILER_DEPENDS= \
	${RUBY_PKGPREFIX}-actionmailer${_RAILS_DEP}:../../mail/ruby-actionmailer${RUBY_RAILS}
RUBY_RAILTIES_DEPENDS= \
	${RUBY_PKGPREFIX}-railties${_RAILS_DEP}:../../devel/ruby-railties${RUBY_RAILS}
RUBY_RAILS_DEPENDS= \
	${RUBY_PKGPREFIX}-rails${_RAILS_DEP}:../../www/ruby-rails${RUBY_RAILS}
RUBY_ACTIONVIEW_DEPENDS= \
	${RUBY_PKGPREFIX}-actionview${_RAILS_DEP}:../../www/ruby-actionview${RUBY_RAILS}
RUBY_ACTIVEJOB_DEPENDS= \
	${RUBY_PKGPREFIX}-activejob${_RAILS_DEP}:../../devel/ruby-activejob${RUBY_RAILS}
RUBY_ACTIONCABLE_DEPENDS= \
	${RUBY_PKGPREFIX}-actioncable${_RAILS_DEP}:../../www/ruby-actioncable${RUBY_RAILS}
RUBY_ACTIVESTORAGE_DEPENDS= \
	${RUBY_PKGPREFIX}-activestorage${_RAILS_DEP}:../../devel/ruby-activestorage${RUBY_RAILS}
.if ${RUBY_RAILS} >= 60
RUBY_ACTIONMAILBOX_DEPENDS= \
	${RUBY_PKGPREFIX}-actionmailbox${_RAILS_DEP}:../../mail/ruby-actionmailbox${RUBY_RAILS}
RUBY_ACTIONTEXT_DEPENDS= \
	${RUBY_PKGPREFIX}-actiontext${_RAILS_DEP}:../../textproc/ruby-actiontext${RUBY_RAILS}
.endif

.endif
