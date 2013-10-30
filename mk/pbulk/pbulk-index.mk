#	$NetBSD: pbulk-index.mk,v 1.19 2013/10/30 06:18:34 dholland Exp $

# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to the parallel bulk build
# tree-scanning code.
#
# The following are the "public" targets provided by this module:
#
#	pbulk-index
#	pbulk-index-item

#
# _PBULK_MULTI lists the multi-package variable.
# For each class the following variables are provided:
#	_PBULK_MULTI_LIST.foo enumerates the supported settings
#	_PBULK_MULTI_VAR.foo forces a specific version
#	_PBULK_MULTI_DEFAULT.foo contains the default value

_PBULK_MULTI?=	apache lua mysql php postgresql python ruby

_PBULK_MULTI_LIST.apache=	PKG_APACHE_ACCEPTED
_PBULK_MULTI_VAR.apache=	PKG_APACHE
_PBULK_MULTI_DEFAULT.apache=	PKG_APACHE_DEFAULT

_PBULK_MULTI_LIST.lua=		_LUA_VERSIONS_ACCEPTED
_PBULK_MULTI_VAR.lua=		LUA_VERSION_REQD
_PBULK_MULTI_DEFAULT.lua=	LUA_VERSION_DEFAULT

_PBULK_MULTI_LIST.mysql=	MYSQL_VERSIONS_ACCEPTED
_PBULK_MULTI_VAR.mysql=		MYSQL_VERSION_REQD
_PBULK_MULTI_DEFAULT.mysql=	MYSQL_VERSION_DEFAULT

_PBULK_MULTI_LIST.php=		PHP_VERSIONS_ACCEPTED
_PBULK_MULTI_VAR.php=		PHP_VERSION_REQD
_PBULK_MULTI_DEFAULT.php=	PHP_VERSION_DEFAULT

_PBULK_MULTI_LIST.postgresql=		PGSQL_VERSIONS_ACCEPTED
_PBULK_MULTI_VAR.postgresql=		PGSQL_VERSION_REQD
_PBULK_MULTI_DEFAULT.postgresql=	PGSQL_VERSION_DEFAULT

_PBULK_MULTI_LIST.python=	_PYTHON_VERSIONS_ACCEPTED
_PBULK_MULTI_VAR.python=	PYTHON_VERSION_REQD
_PBULK_MULTI_DEFAULT.python=	PYTHON_VERSION_DEFAULT

_PBULK_MULTI_LIST.ruby=		RUBY_VERSION_SUPPORTED
_PBULK_MULTI_VAR.ruby=		RUBY_VERSION_REQD
_PBULK_MULTI_DEFAULT.ruby=	RUBY_VERSION_DEFAULT

.PHONY: pbulk-index pbulk-index-item

# Find all classes with more than one supported setting.
# Undefined list variables are handled like a single default value,
# empty list variables are checked afterwards.
#
# For each such class, reorder the supported values to list
# the default value first.  This is important for packages that
# don't follow the module naming conventions.

.if !defined(NO_MULTI_PKG)
. for _t in ${_PBULK_MULTI}
.  if defined(${_PBULK_MULTI_LIST.${_t}}) && !empty(${_PBULK_MULTI_LIST.${_t}})
.    if ${${_PBULK_MULTI_LIST.${_t}}:[\#]} != 1 || \
        !empty(${_PBULK_MULTI_LIST.${_t}}:N${_PBULK_MULTI_DEFAULT.${_t}})
_PBULK_MULTI_NEEDED:=	${_t} ${_PBULK_MULTI_NEEDED}
_PBULK_SORTED_LIST.${_t}:= \
	${${_PBULK_MULTI_LIST.${_t}}:M${${_PBULK_MULTI_DEFAULT.${_t}}}} \
	${${_PBULK_MULTI_LIST.${_t}}:N${${_PBULK_MULTI_DEFAULT.${_t}}}}
.    endif
.  endif
. endfor
.endif

.if !defined(_PBULK_MULTI_NEEDED)
# No multi-package handling needed, directly print the item.
pbulk-index: pbulk-index-item
.else
#
# Use an ODE for loop to compute the carthesian product of
# the support settings.  This expands to something like
#
#	for apache in apache13 apache2; do \
#		_PBULK_MULTI_VALUE.apache=$apache; \
#		export _PBULK_MULTI_VALUE.apache; \
#		PKG_APACHE=$apache; \
#		export PKG_APACHE; \
#		for php in 4 5; do \
#		_PBULK_MULTI_VALUE.php=$php; \
#		export _PBULK_MULTI_VALUE.php; \
#		PHP_VERSION_REQD=$php; \
#		export PHP_VERSION_REQD;
#
# Because the ODE expansion happens in the same shell instance,
# make gets the environment variables in the inner-most loop.
# A second ODE for loop is used to close the shell for loops.
#
pbulk-index:
	@set -e; ${_PBULK_MULTI_NEEDED:@._t.@\
		for ${._t.} in ${_PBULK_SORTED_LIST.${._t.}}; do \
			_PBULK_MULTI_VALUE_${._t.}=$$${._t.}; \
			export _PBULK_MULTI_VALUE_${._t.}; \
			${_PBULK_MULTI_VAR.${._t.}}=$$${._t.}; \
			export ${_PBULK_MULTI_VAR.${._t.}};@} \
	${MAKE} pbulk-index-item \
		${_PBULK_MULTI_NEEDED:@._t.@;done@}
.endif

pbulk-index-item:
	@echo "PKGNAME="${PKGNAME:Q}
	@echo "ALL_DEPENDS="${_ALL_DEPENDS:Q}
	@echo "PKG_SKIP_REASON="${PKG_SKIP_REASON:Q}
	@echo "PKG_FAIL_REASON="${PKG_FAIL_REASON:Q}
	@echo "NO_BIN_ON_FTP="${NO_BIN_ON_FTP:Q}
	@echo "RESTRICTED="${RESTRICTED:Q}
	@echo "CATEGORIES="${CATEGORIES:Q}
	@echo "MAINTAINER="${MAINTAINER:Q}
	@echo "USE_DESTDIR="${_USE_DESTDIR:Q}
	@echo "BOOTSTRAP_PKG="${BOOTSTRAP_PKG}
	@echo "USERGROUP_PHASE="${USERGROUP_PHASE:Q}
	@echo "SCAN_DEPENDS="${.MAKE.MAKEFILES:Q}
.if defined(_PBULK_MULTI_NEEDED)
	@printf "MULTI_VERSION="
.for _t in ${_PBULK_MULTI_NEEDED}
	@printf " %s=%s" ${_PBULK_MULTI_VAR.${_t}:Q} ${_PBULK_MULTI_VALUE_${_t}:Q}
.endfor
	@printf "\n"
.endif

pbulk-save-wrkdir:
	${RUN} [ ! -d ${WRKDIR} ] || cd ${WRKDIR} && ${TAR} cfz ${INTO:Q} .
