# $NetBSD: gem-vars.mk,v 1.13 2022/01/14 15:42:08 taca Exp $
#
# This Makefile fragment defines various make(1) variables for Ruby gems
# support.
#
.if !defined(_RUBYGEM_VARS_MK)
_RUBYGEM_VARS_MK=	# defined

RUBYGEM_VERBOSE?=	No

RUBYGEM_LANG?=	en_US.UTF-8
RUBYGEM_ENV?=	LANG=${RUBYGEM_LANG} LC_CTYPE=${RUBYGEM_LANG}

_RUBY_GEM_MAJOR=	${RUBY_RUBYGEMS_VER:C/([0-9]+)\..*/\1/}
_RUBY_GEM_MINOR=	${RUBY_RUBYGEMS_VER:C/[0-9]+\.([0-9]+)\..*/\1/}

PLIST_VARS+=	ruby_plugins

GEM_EXTSDIR=	${GEM_EXTSBASE}/${GEM_NAME}

PLIST_SUBST+=	GEM_EXTSDIR=${GEM_EXTSDIR}

.if ${_RUBY_GEM_MAJOR} >= 3 && ${_RUBY_GEM_MINOR} >= 2
PLIST.ruby_plugins=	YES
.endif

.endif
