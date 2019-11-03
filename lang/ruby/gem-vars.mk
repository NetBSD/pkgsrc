# $NetBSD: gem-vars.mk,v 1.9 2019/11/03 19:04:06 rillig Exp $
#
# This Makefile fragment defines various make(1) variables for Ruby gems
# support.
#
.if !defined(_RUBYGEM_VARS_MK)
_RUBYGEM_VARS_MK=	# defined

# Specify GEM_PATH
GEM_PATH?=	${PREFIX}/${GEM_HOME}

# Base directory for Gems
MAKE_ENV+=	GEM_PATH=${GEM_PATH}

RUBYGEM_LANG?=	en_US.UTF-8
RUBYGEM_ENV?=	LANG=${RUBYGEM_LANG} LC_CTYPE=${RUBYGEM_LANG}

RUBYGEM=	${LOCALBASE}/bin/${RUBYGEM_NAME}

GEM_EXTSDIR_NEEDS_SUBDIR?=	yes

.if exists(${RUBYGEM})
RUBY_GEM_ARCH!=	${RUBYGEM} environment platform | ${SED} -e 's|.*:||'

.  if !empty(GEM_EXTSDIR_NEEDS_SUBDIR:M[nN][oO])
GEM_EXTSDIR=	${GEM_HOME}/extensions/${RUBY_GEM_ARCH}/${RUBY_VER_DIR}
.  else
GEM_EXTSDIR=	${GEM_HOME}/extensions/${RUBY_GEM_ARCH}/${RUBY_VER_DIR}/${GEM_NAME}
.  endif

.  if !empty(GEM_EXTSDIR)
PLIST_SUBST+=		GEM_EXTSDIR=${GEM_EXTSDIR}
.  else
PLIST_SUBST+=		GEM_EXTSDIR="@comment "
.  endif
.endif

.endif
