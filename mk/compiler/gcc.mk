# $NetBSD: gcc.mk,v 1.36 2004/02/05 03:35:20 jlam Exp $

.if !defined(COMPILER_GCC_MK)
COMPILER_GCC_MK=	one

GCC_REQD?=	2.8.0

# _GCC_DIST_VERSION is the highest version of GCC installed by the pkgsrc
# without the PKGREVISIONs.
#
_GCC_DIST_VERSION=	3.3.2

# _GCC2_PATTERNS matches N s.t. N <= 2.95.3.
_GCC2_PATTERNS=	2.8 2.8.* 2.9 2.9.* 2.[1-8][0-9] 2.[1-8][0-9].*	\
		2.9[0-4] 2.9[0-4].* 2.95 2.95.[0-3]

# _GCC3_PATTERNS matches N s.t. 2.95.3 < N.
_GCC3_PATTERNS=	2.95.[4-9]* 2.95.[1-9][0-9]* 2.9[6-9] 2.9[6-9].*	\
		2.[1-9][0-9][0-9]* 3.* [4-9]*

_CC:=	${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.  for _dir_ in ${PATH:C/\:/ /g}
.    if empty(_CC:M/*)
.      if exists(${_dir_}/${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//})
_CC:=	${_dir_}/${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.      endif
.    endif
.  endfor

.  if !defined(_GCC_VERSION)
_GCC_VERSION_STRING!=	\
	( ${_CC} -v 2>&1 | ${GREP} 'gcc version' ) 2>/dev/null || ${ECHO} 0
.    if !empty(_GCC_VERSION_STRING:Megcs*)
_GCC_VERSION=	2.8.1		# egcs is considered to be gcc-2.8.1.
.    elif !empty(_GCC_VERSION_STRING:Mgcc*)
_GCC_VERSION!=	${_CC} -dumpversion
.    else
_GCC_VERSION=	0
.    endif
.  endif
_GCC_PKG=	gcc-${_GCC_VERSION}

.  if !empty(_CC:M${LOCALBASE}/*)
_IS_BUILTIN_GCC=	NO
GCC_REQD+=		${_GCC_VERSION}
.  else
.    if !empty(_CC:M/*)
#
# GCC in older versions of Darwin report "Apple Computer ... based on gcc
# version ...", so we can't just grep for "^gcc".
#
.      if ${_GCC_VERSION} != "0"
_IS_BUILTIN_GCC=	YES
.      else
_IS_BUILTIN_GCC=	NO
.      endif
.    else
_IS_BUILTIN_GCC=	NO
.    endif
.  endif

# Distill the GCC_REQD list into a single _GCC_REQD value that is the
# highest version of GCC required.
#
_GCC_STRICTEST_REQD?=	none
.  for _version_ in ${GCC_REQD}
.    for _pkg_ in gcc-${_version_}
.      if ${_GCC_STRICTEST_REQD} == "none"
_GCC_PKG_SATISFIES_DEP=		YES
.        for _vers_ in ${GCC_REQD}
.          if !empty(_GCC_PKG_SATISFIES_DEP:M[yY][eE][sS])
_GCC_PKG_SATISFIES_DEP!=	\
	if ${PKG_ADMIN} pmatch 'gcc>=${_vers_}' ${_pkg_}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.          endif
.        endfor
.        if !empty(_GCC_PKG_SATISFIES_DEP:M[yY][eE][sS])
_GCC_STRICTEST_REQD=	${_version_}
.        endif
.      endif
.    endfor
.  endfor
_GCC_REQD=	${_GCC_STRICTEST_REQD}

# Determine whether we require GCC-2.x or GCC-3.x by examining _GCC_REQD.
_NEED_GCC2?=	no
.  for _pattern_ in ${_GCC2_PATTERNS}
.    if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC2=	yes
.    endif
.  endfor
_NEED_GCC3?=	no
.  for _pattern_ in ${_GCC3_PATTERNS}
.    if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC3=	yes
.    endif
.  endfor

.  if !empty(_NEED_GCC2:M[yY][eE][sS])
#
# We require gcc-2.x in the lang/gcc directory.
#
_GCC_PKGBASE=		gcc
LANGUAGES.gcc=		c c++ fortran objc
_LANGUAGES.gcc=		# empty
.    for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gcc+=	${LANGUAGES.gcc:M${_lang_}}
.    endfor
.    if !empty(PKGPATH:Mlang/gcc)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.    endif
.    if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc
_GCC_DEPENDENCY=	gcc>=${_GCC_REQD}:../../lang/gcc
.      if !empty(_LANGUAGES.gcc:Mc++)
USE_GCC_SHLIB?=		yes
.      endif
.    endif
.  elif !empty(_NEED_GCC3:M[yY][eE][sS])
#
# We require gcc-3.x in the lang/gcc3-* directories.
#
_GCC_PKGBASE=		gcc3-c
LANGUAGES.gcc=		c c++ fortran java objc
_LANGUAGES.gcc=		# empty
.    for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gcc+=	${LANGUAGES.gcc:M${_lang_}}
.    endfor
.    if !empty(PKGPATH:Mlang/gcc3-c)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.    endif
.    if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc:Mc)
_GCC_PKGSRCDIR=		../../lang/gcc3-c
_GCC_DEPENDENCY=	gcc3-c>=${_GCC_REQD}:../../lang/gcc3-c
.    endif
.  endif
_GCC_DEPENDS=		${_GCC_PKGBASE}>=${_GCC_REQD}

.  if defined(_NEED_GCC3)
.    if !empty(PKGPATH:Mlang/gcc3-c++)
_IGNORE_GCC3CXX=	yes
MAKEFLAGS+=		_IGNORE_GCC3CXX=yes
.    endif
.    if !defined(_IGNORE_GCC3CXX) && !empty(_LANGUAGES.gcc:Mc++)
_GCC_PKGSRCDIR+=	../../lang/gcc3-c++
_GCC_DEPENDENCY+=	gcc3-c++>=${_GCC_REQD}:../../lang/gcc3-c++
USE_GCC_SHLIB?=		yes
.    endif
.    if !empty(PKGPATH:Mlang/gcc3-f77)
_IGNORE_GCC3F77=	yes
MAKEFLAGS+=		_IGNORE_GCC3F77=yes
.    endif
.    if !defined(_IGNORE_GCC3F77) && !empty(_LANGUAGES.gcc:Mfortran)
_GCC_PKGSRCDIR+=	../../lang/gcc3-f77
_GCC_DEPENDENCY+=	gcc3-f77>=${_GCC_REQD}:../../lang/gcc3-f77
USE_GCC_SHLIB?=		yes
.    endif
.  endif

.  if defined(_IGNORE_GCC)
_USE_PKGSRC_GCC=	NO
.  endif

.  if !defined(_USE_PKGSRC_GCC)
.    if !empty(_IS_BUILTIN_GCC:M[nN][oO])
_USE_PKGSRC_GCC=	YES
.    else
_GCC_TEST_DEPENDS=	gcc>=${_GCC_REQD}
_USE_PKGSRC_GCC!=	\
	if ${PKG_ADMIN} pmatch '${_GCC_TEST_DEPENDS}' ${_GCC_PKG}; then	\
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.    endif
.  endif

# Check if any of the versions of GCC in pkgsrc can satisfy the _GCC_REQD
# requirement.
#
.  if !defined(_NEED_NEWER_GCC)
_PKGSRC_GCC_VERSION=	${_GCC_PKGBASE}-${_GCC_DIST_VERSION}
_NEED_NEWER_GCC!=	\
	if ${PKG_ADMIN} pmatch '${_GCC_DEPENDS}' ${_PKGSRC_GCC_VERSION}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_NEED_NEWER_GCC="${_NEED_NEWER_GCC}"
.  endif
.  if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS]) && \
    !empty(_NEED_NEWER_GCC:M[yY][eE][sS])
PKG_SKIP_REASON=	"Unable to satisfy dependency: ${_GCC_DEPENDS}"
.  endif

.  if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
#
# Ensure that the correct rpath is passed to the linker if we need to
# link against gcc shared libs.
#
_GCC_SUBPREFIX!=	\
	if ${PKG_INFO} -qe ${_GCC_PKGBASE}; then			\
		${PKG_INFO} -f ${_GCC_PKGBASE} |			\
		${GREP} "File:.*bin/gcc" |				\
		${SED} -e "s/.*File: *//;s/bin\/gcc.*//;q";		\
	else								\
		case ${_CC} in						\
		${LOCALBASE}/*)						\
			subprefix="${_CC:H:S/\/bin$//:S/${LOCALBASE}\///:S/${LOCALBASE}//}"; \
			case "$${subprefix}" in				\
			"")	${ECHO} "$${subprefix}" ;;		\
			*)	${ECHO} "$${subprefix}/" ;;		\
			esac;						\
			;;						\
		*)							\
			${ECHO} "_GCC_SUBPREFIX_not_found/";		\
			;;						\
		esac;							\
	fi
_GCC_PREFIX=		${LOCALBASE}/${_GCC_SUBPREFIX}
_GCC_ARCHDIR!=		\
	if [ -x ${_GCC_PREFIX}bin/gcc ]; then				\
		${DIRNAME} `${_GCC_PREFIX}bin/gcc --print-libgcc-file-name`; \
	else								\
		${ECHO} "_GCC_ARCHDIR_not_found";			\
	fi
.    if empty(_GCC_ARCHDIR:M*not_found*)
_GCC_PREFIX:=		${_GCC_ARCHDIR:H:H:H:H}/
_GCC_SUBPREFIX:=	${_GCC_ARCHDIR:H:H:H:H:T}/
.    endif
_GCC_LIBDIRS=	${_GCC_ARCHDIR} ${_GCC_PREFIX}lib
_GCC_LDFLAGS=	# empty
.    for _dir_ in ${_GCC_LIBDIRS:N*not_found*}
_GCC_LDFLAGS+=	-L${_dir_} ${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_}
.    endfor
LDFLAGS+=	${_GCC_LDFLAGS}
.  endif

# Point the variables that specify the compiler to the installed
# GCC executables.
#
.  if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.    if exists(${_GCC_PREFIX}bin/gcc) && !empty(_LANGUAGES.gcc:Mc)
CC=		${_GCC_PREFIX}bin/gcc
.    endif
.    if exists(${_GCC_PREFIX}bin/cpp) && !empty(_LANGUAGES.gcc:Mc)
CPP=		${_GCC_PREFIX}bin/cpp
.    endif
.    if exists(${_GCC_PREFIX}bin/g++) && !empty(_LANGUAGES.gcc:Mc++)
CXX=		${_GCC_PREFIX}bin/g++
.    endif
.    if exists(${_GCC_PREFIX}bin/g77) && !empty(_LANGUAGES.gcc:Mfortran)
F77=		${_GCC_PREFIX}bin/g77
PKG_FC:=	${F77}
.    endif
.  endif

# GCC passes flags to the linker using "-Wl,".
_COMPILER_LD_FLAG=	-Wl,

# Pass the required flags to imake to tell it we're using gcc on Solaris.
.  if ${OPSYS} == "SunOS"
IMAKEOPTS+=	-DHasGcc2=YES -DHasGcc2ForCplusplus=YES
.  endif

.  if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.    if exists(${CC})
CC_VERSION!=	if ${CC} -dumpversion > /dev/null 2>&1; then		\
			${ECHO} "gcc-`${CC} -dumpversion`";		\
		else							\
			${ECHO} "gcc-${_GCC_REQD}";			\
		fi
.    else
CC_VERSION=	gcc-${_GCC_REQD}
.    endif
.  else
CC_VERSION=	${_GCC_PKG}
.  endif
.endif	# COMPILER_GCC_MK

# The following section is included only if we're not being included by
# bsd.prefs.mk.
#
.if empty(BSD_PREFS_MK)
.  if empty(COMPILER_GCC_MK:Mtwo)
COMPILER_GCC_MK+=	two

# Prepend the path to the compiler to the PATH.
.    if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.      if exists(${_GCC_PREFIX}bin/gcc) && !empty(_LANGUAGES.gcc)
PATH:=	${_GCC_PREFIX}bin:${PATH}
.      endif
.    else
.      if !empty(_IS_BUILTIN_GCC:M[yY][eE][sS])
.        if !empty(_CC:M/*)
PATH:=	${_CC:H}:${PATH}
.        endif
.      endif
.    endif

# Add the dependency on GCC.
.    if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.      if empty(USE_BUILDLINK2:M[nN][oO])
.        for _dir_ in ${_GCC_PKGSRCDIR}
.          include "${_dir_}/buildlink2.mk"
.        endfor
.      elif !empty(USE_BUILDLINK3:M[yY][eE][sS])
.        for _dir_ in ${_GCC_PKGSRCDIR}
.          include "${_dir_}/buildlink3.mk"
.        endfor
.      else
.        if defined(USE_GCC_SHLIB)
DEPENDS+=	${_GCC_DEPENDENCY}
.        else
BUILD_DEPENDS+=	${_GCC_DEPENDENCY}
.        endif
.      endif
.    endif
.  endif # COMPILER_GCC_MK
.endif	 # BSD_PREFS_MK
