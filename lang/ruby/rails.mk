# $NetBSD: rails.mk,v 1.61 2017/07/18 13:59:04 taca Exp $

.if !defined(_RUBY_RAILS_MK)
_RUBY_RAILS_MK=	# defined

#
# === User-settable variables ===
#
# RUBY_RAILS_DEFAULT
#	Select default Ruby on Rails version.
#
#	Possible values: 32 42
#	Default: 32
#
#
# === Package-settable variables ===
#
# RUBY_RAILS_SUPPORTED
#	The Ruby on Rails versions that are acceptable for the package.
#
#	Possible values: 32 42
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
#	Possible values: 32 42
#

#
# current Ruby on Rails versions.
#
RUBY_RAILS32_VERSION?=	3.2.22.5
RUBY_RAILS42_VERSION?=	4.2.8

RUBY_RAILS_SUPPORTED?=	# defined
RUBY_RAILS_DEFAULT?=	32

RUBY_RAILS_STRICT_DEP?=	no

.if !empty(RUBY_RAILS_SUPPORTED) && ${RUBY_RAILS_SUPPORTED:[\#]} == 1
RUBY_RAILS=			${RUBY_RAILS_SUPPORTED}
.endif

RUBY_RAILS?=	${RUBY_RAILS_DEFAULT}

.if ${RUBY_RAILS} == "42"
RAILS_VERSION:=	${RUBY_RAILS42_VERSION}
.else
RAILS_VERSION:=	${RUBY_RAILS32_VERSION}
.endif

#
# Components of Ruby's version.
#
_RAILS_MAJOR=	${RAILS_VERSION:C/([0-9]+)\..*/\1/}
_RAILS_MINOR=	${RAILS_VERSION:C/([0-9]+)\.([0-9]+)\..*/\2/}
_RAILS_TEENY=	${RAILS_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+).*/\3/}

#
# If RUBY_RAILS_STRICT_DEP is defined, match exact current Ruby no Rails
# version.
# Otherwise allow greater minor version.

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
		RUBY_RAILS_SUPPORTED=${RUBY_RAILS}
#
MULTI+=			RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
			RUBY_RAILS_SUPPORTED=${RUBY_RAILS}

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

.if ${RUBY_RAILS} == "32"
RUBY_ACTIVERESOURCE_DEPENDS= \
	${RUBY_PKGPREFIX}-activeresource${_RAILS_DEP}:../../www/ruby-activeresource${RUBY_RAILS}
.elif ${RUBY_RAILS} == "42"
RUBY_ACTIONVIEW_DEPENDS= \
	${RUBY_PKGPREFIX}-actionview${_RAILS_DEP}:../../www/ruby-actionview${RUBY_RAILS}
RUBY_ACTIVEJOB_DEPENDS= \
	${RUBY_PKGPREFIX}-activejob${_RAILS_DEP}:../../devel/ruby-activejob${RUBY_RAILS}
.endif

.endif
