# $NetBSD: f2c.mk,v 1.1 2005/01/12 15:32:01 jlam Exp $

.if !defined(COMPILER_F2C_MK)
COMPILER_F2C_MK=	defined

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGPATH:Mlang/f2c) || !empty(PKGPATH:Mdevel/patch) || \
    !empty(PKGPATH:Mdevel/libtool-base)
IGNORE_F2C=	yes
MAKEFLAGS+=	IGNORE_F2C=yes
.endif

.if defined(IGNORE_F2C)
_USE_F2C=	NO
.endif

# LANGUAGES.<compiler> is the list of supported languages by the compiler.
# _LANGUAGES.<compiler> is ${LANGUAGES.<compiler>} restricted to the ones
# requested by the package in USE_LANGUAGES.
# 
LANGUAGES.f2c=	fortran
_LANGUAGES.f2c=	# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.f2c+=	${LANGUAGES.f2c:M${_lang_}}
.endfor
.if empty(_LANGUAGES.f2c)
_USE_F2C=	NO
.endif

.if !defined(_USE_F2C)
_USE_F2C=	YES
.endif

.if !empty(_USE_F2C:M[yY][eE][sS])
EVAL_PREFIX+=		_F2CBASE=f2c
_F2CBASE_DEFAULT=	${LOCALBASE}
_F2CBASE?=		${LOCALBASE}

_F2C_DIR=	${WRKDIR}/.f2c
_F2C_VARS=	# empty
.  if !empty(_LANGUAGES.f2c:Mfortran)
PKG_FC?=	${FC}
_F2C_VARS+=	FC
_F2C_FC:=	${_F2C_DIR}/bin/${PKG_FC:T}
_ALIASES.FC+=	f77 f2c-f77
FCPATH=		${_F2CBASE}/bin/f2c-f77
PKG_FC:=	${_F2C_FC}
#
# The f2c-f77 shell script invokes the C compiler, so ensure that it finds
# the cc wrapper for proper transformations.
#
# XXX This shouldn't really be leaking into here, as it breaks encapsulation.
# XXX It should really be handled within the wrapper framework.
#
_WRAP_ENV.FC=	PATH="${WRAPPER_BINDIR}:${_WRAP_PATH}"; export PATH
.  endif

# Prepend the path the to the compiler to the PATH
.  if !empty(_LANGUAGES.f2c)
PREPEND_PATH+=	${_F2C_DIR}/bin
.  endif

# Add the dependency on f2c.
.  if !empty(USE_BUILDLINK3:M[yY][eE][sS])
.    include "../../lang/f2c/buildlink3.mk"
.  else
DEPENDS+=	f2c>=20001205nb3:../../lang/f2c
.  endif

.  if defined(F2C_DIR) && !empty(F2C_DIR)
BUILD_ENV+=	F2C_DIR=${F2C_DIR:Q}
.  endif

# Create symlinks for the compiler into ${WRKDIR}.
.  for _var_ in ${_F2C_VARS}
.    if !target(${_F2C_${_var_}})
override-tools: ${_F2C_${_var_}}
${_F2C_${_var_}}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET:H}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${LN} -fs ${_F2CBASE}/bin/f2c-f77 ${.TARGET}
.      for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -fs ${_F2CBASE}/bin/f2c-f77 ${_alias_};		\
	fi
.      endfor
.    endif
.  endfor
.endif	# _USE_F2C == "yes"

.endif	# COMPILER_F2C_MK
