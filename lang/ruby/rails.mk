# $NetBSD: rails.mk,v 1.54 2016/03/05 05:23:26 taca Exp $

.if !defined(_RUBY_RAILS_MK)
_RUBY_RAILS_MK=	# defined

#
# === User-settable variables ===
#
# RUBY_RAILS_DEFAULT
#	Select default Ruby on Rails version.
#
#	Possible values: 32
#	Default: 32
#
#
# === Package-settable variables ===
#
# RUBY_RAILS_SUPPORTED
#	The Ruby on Rails versions that are acceptable for the package.
#
#	Possible values: 32
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
#	Possible values: 32
#

#
# current Ruby on Rails versions.
#
RUBY_RAILS32_VERSION?=	3.2.22.2

RUBY_RAILS_SUPPORTED?=	# defined
RUBY_RAILS_DEFAULT?=	32

RUBY_RAILS_STRICT_DEP?=	no

.if !empty(RUBY_RAILS_SUPPORTED) && ${RUBY_RAILS_SUPPORTED:[\#]} == 1
RUBY_RAILS=			${RUBY_RAILS_SUPPORTED}
.endif

.if empty(RUBY_RAILS)
_RUBY_INSTALLED_RAILS!= \
	if ${PKG_INFO} -qe "${RUBY_PKGPREFIX}-rack>=1.4" || \
		${PKG_INFO} -qe "${RUBY_PKGPREFIX}-activesupport>=3.2"; then \
		${ECHO} 32; \
	else \
		${ECHO} "none"; \
	fi
. if ${_RUBY_INSTALLED_RAILS} != "none"
RUBY_RAILS:=	${_RUBY_INSTALLED_RAILS}
. else
RUBY_RAILS:=	${RUBY_RAILS_DEFAULT}
. endif
.endif

RUBY_RAILS_VERSION:=	${RUBY_RAILS32_VERSION}

#
# Components of Ruby's version.
#
_RAILS_MAJOR=	${RUBY_RAILS_VERSION:C/([0-9]+)\..*/\1/}
_RAILS_MINOR=	${RUBY_RAILS_VERSION:C/([0-9]+)\.([0-9]+)\..*/\2/}
_RAILS_TEENY=	${RUBY_RAILS_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+).*/\3/}

#
# If RUBY_RAILS_STRICT_DEP is defined, match exact current Ruby no Rails
# version.
# Otherwise allow greater minor version.

.if !empty(RUBY_RAILS_STRICT_DEP:M[yY][eE][sS])
_RAILS_NEXT!=	${EXPR} ${_RAILS_TEENY} + 1
_RAILS_DEP=	\
	>=${RUBY_RAILS_VERSION}<${_RAILS_MAJOR}.${_RAILS_MINOR}.${_RAILS_NEXT}
.else
_RAILS_NEXT!=	${EXPR} ${_RAILS_MINOR} + 1
_RAILS_DEP=	>=${RUBY_RAILS_VERSION}<${_RAILS_MAJOR}.${_RAILS_NEXT}
.endif

#
MAKE_ENV+=	RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
		RUBY_RAILS_SUPPORTED=${RUBY_RAILS}
#
MULTI+=			RUBY_RAILS_DEFAULT=${RUBY_RAILS} \
			RUBY_RAILS_SUPPORTED=${RUBY_RAILS}

RUBY_ACTIVESUPPORT?=	${RUBY_RAILS_VERSION}
RUBY_ACTIONPACK?=	${RUBY_RAILS_VERSION}
RUBY_ACTIVERECORD?=	${RUBY_RAILS_VERSION}
RUBY_ACTIVERESOURCE?=	${RUBY_RAILS_VERSION}
RUBY_ACTIONMAILER?=	${RUBY_RAILS_VERSION}
RUBY_RAILTIES?=		${RUBY_RAILS_VERSION}

RUBY_RAILS32_ACTIVESUPPORT=	../../devel/ruby-activesupport32
RUBY_RAILS32_ACTIVEMODEL=	../../devel/ruby-activemodel32
RUBY_RAILS32_ACTIONPACK=	../../www/ruby-actionpack32
RUBY_RAILS32_ACTIVERECORD=	../../databases/ruby-activerecord32
RUBY_RAILS32_ACTIVERESOURCE=	../../www/ruby-activeresource32
RUBY_RAILS32_ACTIONMAILER=	../../mail/ruby-actionmailer32
RUBY_RAILS32_RAILTIES=		../../devel/ruby-railties32
RUBY_RAILS32_RAILS=		../../www/ruby-rails32

RUBY_ACTIVESUPPORT_DEPENDS= \
	${RUBY_PKGPREFIX}-activesupport${_RAILS_DEP}:${RUBY_RAILS32_ACTIVESUPPORT}
RUBY_ACTIVEMODEL_DEPENDS= \
	${RUBY_PKGPREFIX}-activemodel${_RAILS_DEP}:${RUBY_RAILS32_ACTIVEMODEL}
RUBY_ACTIONPACK_DEPENDS= \
	${RUBY_PKGPREFIX}-actionpack${_RAILS_DEP}:${RUBY_RAILS32_ACTIONPACK}
RUBY_ACTIVERECORD_DEPENDS= \
	${RUBY_PKGPREFIX}-activerecord${_RAILS_DEP}:${RUBY_RAILS32_ACTIVERECORD}
RUBY_ACTIVERESOURCE_DEPENDS= \
	${RUBY_PKGPREFIX}-activeresource${_RAILS_DEP}:${RUBY_RAILS32_ACTIVERESOURCE}
RUBY_ACTIONMAILER_DEPENDS= \
	${RUBY_PKGPREFIX}-actionmailer${_RAILS_DEP}:${RUBY_RAILS32_ACTIONMAILER}
RUBY_RAILTIES_DEPENDS= \
	${RUBY_PKGPREFIX}-railties${_RAILS_DEP}:${RUBY_RAILS32_RAILTIES}
RUBY_RAILS_DEPENDS= \
	${RUBY_PKGPREFIX}-rails${_RAILS_DEP}:${RUBY_RAILS32_RAILS}

.endif
