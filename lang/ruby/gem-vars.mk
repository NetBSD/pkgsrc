# $NetBSD: gem-vars.mk,v 1.12 2021/01/11 11:21:31 taca Exp $
#
# This Makefile fragment defines various make(1) variables for Ruby gems
# support.
#
.if !defined(_RUBYGEM_VARS_MK)
_RUBYGEM_VARS_MK=	# defined

RUBYGEM_VERBOSE?=	No

# Specify GEM_PATH
GEM_PATH?=	${PREFIX}/${GEM_HOME}

# Base directory for Gems
MAKE_ENV+=	GEM_PATH=${GEM_PATH}

RUBYGEM_LANG?=	en_US.UTF-8
RUBYGEM_ENV?=	LANG=${RUBYGEM_LANG} LC_CTYPE=${RUBYGEM_LANG}

RUBYGEM=	${LOCALBASE}/bin/${RUBYGEM_NAME}

GEM_EXTSDIR_NEEDS_SUBDIR?=	yes

GEM_PLUGINSDIR=	${GEM_HOME}/plugins

.if exists(${RUBYGEM})
RUBY_GEM_ARCH!=	${RUBYGEM} environment platform | ${SED} -e 's|.*:||'
RUBY_GEM_VER!= ${RUBYGEM} --version

GEM_EXTSBASE=	${GEM_HOME}/extensions
PLIST_SUBST+=	GEM_EXTSDIR=${GEM_EXTSDIR}
PLIST_SUBST+=	GEM_PLUGINSDIR=${GEM_PLUGINSDIR}

.  if !empty(GEM_EXTSDIR_NEEDS_SUBDIR:M[nN][oO])
GEM_EXTSDIR=	${GEM_EXTSBASE}/${RUBY_GEM_ARCH}/${RUBY_VER_DIR}
.  else
GEM_EXTSDIR=	${GEM_EXTSBASE}/${RUBY_GEM_ARCH}/${RUBY_VER_DIR}/${GEM_NAME}
.  endif

_RUBY_GEM_MAJOR=	${RUBY_GEM_VER:C/([0-9]+)\..*/\1/}
_RUBY_GEM_MINOR=	${RUBY_GEM_VER:C/[0-9]+\.([0-9]+)\..*/\1/}

PLIST_VARS+=	ruby_plugins

.if ${_RUBY_GEM_MAJOR} >= 3 && ${_RUBY_GEM_MINOR} >= 2
PLIST.ruby_plugins=	YES
.endif

.endif

.endif
