# $NetBSD: gcc.mk,v 1.14 2004/02/03 03:47:45 jlam Exp $

.if !defined(COMPILER_GCC_MK)
COMPILER_GCC_MK=	defined

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

_CC=	${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.for _dir_ in ${PATH:C/\:/ /g}
.  if empty(_CC:M/*)
.    if exists(${_dir_}/${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//})
_CC=	${_dir_}/${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.    endif
.  endif
.endfor

.if !empty(_CC:M${LOCALBASE}/*)
_IS_BUILTIN_GCC=	NO
.else
.  if !empty(_CC:M/*)
#
# GCC in older versions of Darwin report "Apple Computer ... based on gcc
# version ...", so we can't just grep for "^gcc".
#
_IS_BUILTIN_GCC!=	\
	if ${_CC} -v 2>&1 | ${GREP} -q "gcc version"; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.  else
_IS_BUILTIN_GCC=	NO
.  endif
.endif

# Distill the GCC_REQD list into a single _GCC_REQD value that is the
# highest version of GCC required.
#
_GCC_STRICTEST_REQD?=	none
.for _version_ in ${GCC_REQD}
.  for _pkg_ in gcc-${_version_}
.    if ${_GCC_STRICTEST_REQD} == "none"
_GCC_PKG_SATISFIES_DEP=		YES
.      for _vers_ in ${GCC_REQD}
.        if !empty(_GCC_PKG_SATISFIES_DEP:M[yY][eE][sS])
_GCC_PKG_SATISFIES_DEP!=	\
	if ${PKG_ADMIN} pmatch 'gcc>=${_vers_}' ${_pkg_}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.      if !empty(_GCC_PKG_SATISFIES_DEP:M[yY][eE][sS])
_GCC_STRICTEST_REQD=	${_version_}
.      endif
.    endif
.  endfor
.endfor
_GCC_REQD=	${_GCC_STRICTEST_REQD}

# Determine whether we require GCC-2.x or GCC-3.x by examining _GCC_REQD.
_NEED_GCC2?=	no
.for _pattern_ in ${_GCC2_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC2=	yes
.  endif
.endfor
_NEED_GCC3?=	no
.for _pattern_ in ${_GCC3_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC3=	yes
.  endif
.endfor

.if defined(_NEED_GCC2)
#
# We require gcc-2.x in the lang/gcc directory.
#
_GCC_PKGBASE=		gcc
LANGUAGES.gcc=		c c++ fortran objc
_LANGUAGES.gcc=		# empty
.  for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gcc=		${LANGUAGES.gcc:M${_lang_}}
.  endfor
.  if !empty(PKGPATH:Mlang/gcc)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  elif !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc
_GCC_DEPENDENCY=	gcc>=${_GCC_REQD}:../../lang/gcc
.    if !empty(_LANGUAGES.gcc:Mc++)
USE_GCC_SHLIB?=		yes
.    endif
.  endif
.elif defined(_NEED_GCC3)
#
# We require gcc-3.x in the lang/gcc3-* directories.
#
_GCC_PKGBASE=		gcc3-c
LANGUAGES.gcc=		c c++ fortran java objc
_LANGUAGES.gcc=		# empty
.  for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gcc=		${LANGUAGES.gcc:M${_lang_}}
.  endfor
.  if !empty(PKGPATH:Mlang/gcc3-c)
_IGNORE_GCC3C=		yes
MAKEFLAGS+=		_IGNORE_GCC3C=yes
.  elif !empty(_LANGUAGES.gcc:Mc)
_GCC_PKGSRCDIR=		../../lang/gcc3-c
_GCC_DEPENDENCY=	gcc3-c>=${_GCC_REQD}:../../lang/gcc3-c
.  endif
.  if !empty(PKGPATH:Mlang/gcc3-c++)
_IGNORE_GCC3CXX=	yes
MAKEFLAGS+=		_IGNORE_GCC3CXX=yes
.  elif !empty(_LANGUAGES.gcc:Mc++)
_GCC_PKGSRCDIR+=	../../lang/gcc3-c++
_GCC_DEPENDENCY+=	gcc3-c++>=${_GCC_REQD}:../../lang/gcc3-c++
USE_GCC_SHLIB?=		yes
.  endif
.  if !empty(PKGPATH:Mlang/gcc3-f77)
_IGNORE_GCC3F77=	yes
MAKEFLAGS+=		_IGNORE_GCC3F77=yes
.  elif !empty(_LANGUAGES.gcc:Mfortran)
_GCC_PKGSRCDIR+=	../../lang/gcc3-f77
_GCC_DEPENDENCY+=	gcc3-f77>=${_GCC_REQD}:../../lang/gcc3-f77
USE_GCC_SHLIB?=		yes
.  endif
.endif
_GCC_DEPENDS=		${_GCC_PKGBASE}>=${_GCC_REQD}

.if defined(_IGNORE_GCC) || defined(_IGNORE_GCC3C)
_USE_PKGSRC_GCC=	NO
.endif

.if !defined(_USE_PKGSRC_GCC)
.  if !empty(_IS_BUILTIN_GCC:M[nN][oO])
_USE_PKGSRC_GCC=	YES
.  else
_GCC_VERSION_STRING!=	${_CC} -v 2>&1 | ${GREP} 'gcc version'
.    if !empty(_GCC_VERSION_STRING:Megcs*)
_GCC_VERSION=	2.8.1		# egcs is considered to be gcc-2.8.1.
.    elif !empty(_GCC_VERSION_STRING:Mgcc*)
_GCC_VERSION!=	${_CC} -dumpversion
.    else
_GCC_VERSION=	0
.    endif
_GCC_TEST_DEPENDS=	gcc>=${_GCC_REQD}
_GCC_PKG=		gcc-${_GCC_VERSION}
_USE_PKGSRC_GCC!=	\
	if ${PKG_ADMIN} pmatch '${_GCC_TEST_DEPENDS}' ${_GCC_PKG}; then	\
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
.endif

.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
#
# Ensure that the correct rpath is passed to the linker if we need to
# link against gcc shared libs.
#
_COMPILER_LD_FLAG=	-Wl,
.  if !empty(_CC:M${LOCALBASE}/*)
_GCC_SUBPREFIX=		${_CC:T:S/\/bin$//:S/${LOCALBASE}\///:S/${LOCALBASE}//}/
.  else
_GCC_SUBPREFIX!=	\
	if ${PKG_INFO} -qe ${_GCC_PKGBASE}; then			\
		${PKG_INFO} -f ${_GCC_PKGBASE} |			\
		${GREP} "File:.*bin/gcc" |				\
		${SED} -e "s/.*File: *//;s/bin\/gcc.*//;q";		\
	else								\
		${ECHO} "not_found/";					\
	fi
.  endif
_GCC_PREFIX=		${LOCALBASE}/${_GCC_SUBPREFIX}
_GCC_ARCHDIR!=		\
	if [ -x ${_GCC_PREFIX}bin/gcc ]; then				\
		${DIRNAME} `${_GCC_PREFIX}bin/gcc --print-libgcc-file-name`; \
	else								\
		${ECHO} "not_found";					\
	fi
_GCC_LDFLAGS=	# empty
.  for _dir_ in ${_GCC_ARCHDIR} ${_GCC_PREFIX}lib
_GCC_LDFLAGS+=	-L${_dir_} ${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_}
.  endfor
LDFLAGS+=	${_GCC_LDFLAGS}
.endif

# Check if any of the versions of GCC in pkgsrc can satisfy the _GCC_REQD
# requirement.
#
.if !defined(_NEED_NEWER_GCC)
_PKGSRC_GCC_VERSION=	${_GCC_PKGBASE}-${_GCC_DIST_VERSION}
_NEED_NEWER_GCC!=	\
	if ${PKG_ADMIN} pmatch '${_GCC_DEPENDS}' ${_PKGSRC_GCC_VERSION}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
MAKEFLAGS+=	_NEED_NEWER_GCC="${_NEED_NEWER_GCC}"
.endif
.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS]) && \
    !empty(_NEED_NEWER_GCC:M[yY][eE][sS])
PKG_SKIP_REASON=	"Unable to satisfy dependency: ${_GCC_DEPENDS}"
.endif

# Add the dependency on GCC.
.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.  if empty(USE_BUILDLINK2:M[nN][oO])
.    for _dir_ in ${_GCC_PKGSRCDIR}
.      include "${_dir_}/buildlink2.mk"
.    endfor
.  elif !empty(USE_BUILDLINK3:M[yY][eE][sS])
.    for _dir_ in ${_GCC_PKGSRCDIR}
.      include "${_dir_}/buildlink3.mk"
.    endfor
.  else
.    if defined(USE_GCC_SHLIB)
DEPENDS+=	${_GCC_DEPENDENCY}
.    else
BUILD_DEPENDS+=	${_GCC_DEPENDENCY}
.    endif
.  endif
.endif

# Point the variables that specify the compiler to the installed
# GCC executables.
#
.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.  if exists(${_GCC_PREFIX}bin/gcc) && !empty(_LANGUAGES.gcc)
PATH:=		${_GCC_PREFIX}bin:${PATH}
.  endif
.  if exists(${_GCC_PREFIX}bin/gcc) && !empty(_LANGUAGES.gcc:Mc)
CC=		${_GCC_PREFIX}bin/gcc
.  endif
.  if exists(${_GCC_PREFIX}bin/cpp) && !empty(_LANGUAGES.gcc:Mc)
CPP=		${_GCC_PREFIX}bin/cpp
.  endif
.  if exists(${_GCC_PREFIX}bin/g++) && !empty(_LANGUAGES.gcc:Mc++)
CXX=		${_GCC_PREFIX}bin/g++
.  endif
.  if exists(${_GCC_PREFIX}bin/g77) && !empty(_LANGUAGES.gcc:Mfortran)
F77=		${_GCC_PREFIX}bin/g77
PKG_FC:=	${F77}
.  endif
.else
.  if !empty(_IS_BUILTIN_GCC:M[yY][eE][sS])
.    if !empty(_CC:M/*)
PATH:=		${_CC:H}:${PATH}
.    endif
.  endif
.endif

# Pass the required flags to imake to tell it we're using gcc on Solaris.
.if ${OPSYS} == "SunOS"
IMAKEOPTS+=	-DHasGcc2=YES -DHasGcc2ForCplusplus=YES
.endif

.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
CC_VERSION!=	if ${CC} -dumpversion > /dev/null 2>&1; then		\
			${ECHO} "gcc-`${CC} -dumpversion`";		\
		else							\
			${ECHO} "gcc-${_GCC_REQD}";			\
		fi
.else
CC_VERSION=	${_GCC_PKG}
.endif

.endif	# COMPILER_GCC_MK
