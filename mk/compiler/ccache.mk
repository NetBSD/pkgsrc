# $NetBSD: ccache.mk,v 1.23 2005/01/10 19:38:53 jlam Exp $

.if !defined(COMPILER_CCACHE_MK)
COMPILER_CCACHE_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGPATH:Mdevel/ccache) || !empty(PKGPATH:Mdevel/patch)
IGNORE_CCACHE=	yes
MAKEFLAGS+=	IGNORE_CCACHE=yes
.endif

.if defined(IGNORE_CCACHE)
_USE_CCACHE=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.ccache=	c c++
_LANGUAGES.ccache=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.ccache+=	${LANGUAGES.ccache:M${_lang_}}
.endfor
.if empty(_LANGUAGES.ccache)
_USE_CCACHE=	NO
.endif

.if !defined(_USE_CCACHE)
_USE_CCACHE=	YES
.endif

.if !empty(_USE_CCACHE:M[yY][eE][sS])
EVAL_PREFIX+=		_CCACHEBASE=ccache
_CCACHEBASE_DEFAULT=	${LOCALBASE}
_CCACHEBASE?=		${LOCALBASE}

_CCACHE_DIR=	${WRKDIR}/.ccache
_CCACHE_VARS=	# empty
.  if !empty(_LANGUAGES.ccache:Mc)
PKG_CC?=	${CC}
_CCACHE_VARS+=	CC
_CCACHE_CC:=	${_CCACHE_DIR}/bin/${PKG_CC:T}
_ALIASES.CC+=	cc
PKG_CC:=	${_CCACHE_CC}
.  endif
.  if !empty(_LANGUAGES.ccache:Mc++)
PKG_CXX?=	${CXX}
_CCACHE_VARS+=	CXX
_CCACHE_CXX:=	${_CCACHE_DIR}/bin/${PKG_CXX:T}
_ALIASES.CXX+=	c++
PKG_CXX:=	${_CCACHE_CXX}
.  endif

# Prepend the path the to the compiler to the PATH
.  if !empty(_LANGUAGES.ccache)
PREPEND_PATH+=	${_CCACHE_DIR}/bin
.  endif

# Add the dependency on ccache.
BUILD_DEPENDS+=	ccache-[0-9]*:../../devel/ccache

# Override the compiler-specific hash with the version string for the
# compiler.
#
BUILD_ENV+=	CCACHE_HASHCC=${CC_VERSION_STRING:Q}

.  if defined(CCACHE_DIR) && !empty(CCACHE_DIR)
BUILD_ENV+=	CCACHE_DIR=${CCACHE_DIR:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_CCACHE_VARS}
.    if !target(${_CCACHE_${_var_}})
override-tools: ${_CCACHE_${_var_}}
${_CCACHE_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_CCACHEBASE}/bin/ccache ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_CCACHEBASE}/bin/ccache ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_CCACHE == "yes"

.endif	# COMPILER_CCACHE_MK
