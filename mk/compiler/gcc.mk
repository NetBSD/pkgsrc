# $NetBSD: gcc.mk,v 1.3 2004/02/01 01:23:37 jlam Exp $

.if !defined(COMPILER_GCC_MK)
COMPILER_GCC_MK=	defined

GCC_REQD?=	2.8.0

# _GCC_DIST_VERSION is the highest version of GCC installed by the pkgsrc
# without the PKGREVISIONs.
#
_GCC_DIST_VERSION=	3.3

# _GCC2_PATTERNS matches N s.t. N <= 2.95.3.
_GCC2_PATTERNS=	2.8 2.8.* 2.9 2.9.* 2.[1-8][0-9] 2.[1-8][0-9].*	\
		2.9[0-4] 2.9[0-4].* 2.95 2.95.[0-3]

# _GCC3_PATTERNS matches N s.t. 2.95.3 < N.
_GCC3_PATTERNS=	2.95.[4-9]* 2.95.[1-9][0-9]* 2.9[6-9] 2.9[6-9].*	\
		2.[1-9][0-9][0-9]* 3.* [4-9]*

.if !defined(_IS_BUILTIN_GCC)
#
# GCC in older versions of Darwin report "Apple Computer ... based on gcc
# version ...", so we can't just grep for "^gcc".
#
_IS_BUILTIN_GCC!=	\
	gccpath="`${TYPE} ${CC} | ${AWK} '{ print $$NF }'`";		\
	case $$gccpath in						\
	${LOCALBASE}/*)							\
		${ECHO} "NO";						\
		;;							\
	*)								\
		if ${CC} -v 2>&1 | ${GREP} -q 'gcc version'; then	\
			${ECHO} "YES";					\
		else							\
			${ECHO} "NO";					\
		fi;							\
		;;							\
	esac
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
.for _pattern_ in ${_GCC2_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_GCC2_REQD:=	${_GCC_REQD}
.  endif
.endfor
.for _pattern_ in ${_GCC3_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_GCC3_REQD:=	${_GCC_REQD}
.  endif
.endfor
.if defined(_GCC2_REQD)
_GCC_REQD:=		${_GCC2_REQD}
_GCC_PKGBASE=		gcc
_GCC_PKGSRCDIR=		../../lang/gcc
.  if !empty(PKGPATH:Mlang/gcc)
_IGNORE_GCC_REQD=	yes
MAKEFLAGS+=		_IGNORE_GCC_REQD=yes
.  endif
.elif defined(_GCC3_REQD)
_GCC_REQD:=		${_GCC3_REQD}
_GCC_PKGBASE=		gcc3
_GCC_PKGSRCDIR=		../../lang/gcc3
.  if !empty(PKGPATH:Mlang/gcc3)
_IGNORE_GCC_REQD=	yes
MAKEFLAGS+=		_IGNORE_GCC_REQD=yes
.  endif
.endif
_GCC_DEPENDS=		${_GCC_PKGBASE}>=${_GCC_REQD}

.if defined(_IGNORE_GCC_REQD)
_USE_PKGSRC_GCC=	NO
.endif

.if !defined(_USE_PKGSRC_GCC)
.  if !empty(_IS_BUILTIN_GCC:M[nN][oO])
_USE_PKGSRC_GCC=	YES
.  else
_GCC_VERSION_STRING!=	${CC} -v 2>&1 | ${GREP} 'gcc version'
.    if !empty(_GCC_VERSION_STRING:Megcs*)
_GCC_VERSION=	2.8.1		# egcs is considered to be gcc-2.8.1.
.    elif !empty(_GCC_VERSION_STRING:Mgcc*)
_GCC_VERSION!=	${CC} -dumpversion
.    else
_GCC_VERSION=	0
.    endif
#
# Note that the actual package name isn't really important here as we're
# just trying to do comparisons of version numbers.
#
_GCC_TEST_DEPENDS=	cc>=${GCC_REQD}
_GCC_PKG=		cc-${_GCC_VERSION}
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
_GCC_SUBPREFIX!=	\
	if ${PKG_INFO} -qe ${_GCC_PKGBASE}; then			\
		${PKG_INFO} -f ${_GCC_PKGBASE} |			\
		${GREP} "File:.*bin/gcc" |				\
		${SED} -e "s/.*File: *//;s/bin\/gcc.*//;q";		\
	else								\
		${ECHO} "not_found/";					\
	fi
_GCC_PREFIX=		${LOCALBASE}/${_GCC_SUBPREFIX}
_GCC_LIBGCCDIR!=	\
	if [ -x ${_GCC_PREFIX}bin/gcc ]; then				\
		${DIRNAME} `${_GCC_PREFIX}bin/gcc --print-libgcc-file-name`; \
	else								\
		${ECHO} "not_found";					\
	fi
_GCC_ARCHSUBDIR=	${_GCC_LIBGCCDIR:S|^${LOCALBASE}/${_GCC_SUBPREFIX}||}
_GCC_ARCHDIR=		${_GCC_PREFIX}${_GCC_ARCHSUBDIR}

_GCC_LDFLAGS=	# empty
.for _dir_ in ${_GCC_ARCHDIR} ${_GCC_PREFIX}lib
_GCC_LDFLAGS+=	-L${_dir_} ${_COMPILER_LD_FLAG}${RPATH_FLAG}${_dir_}
.endfor
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
.    include "${_GCC_PKGSRCDIR}/buildlink2.mk"
#.  elif !empty(USE_BUILDLINK3:M[yY][eE][sS])
#.    include "${_GCC_PKGSRCDIR}/buildlink3.mk"
.  else
.    if defined(USE_GCC_SHLIB)
DEPENDS+=	${_GCC_DEPENDS}:${_GCC_PKGSRCDIR}
.    else
BUILD_DEPENDS+=	${_GCC_DEPENDS}:${_GCC_PKGSRCDIR}
.    endif
.  endif
.endif

# Point the variables that specify the compiler to the installed
# GCC executables.
#
.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.  if exists(${_GCC_PREFIX}bin/gcc)
PATH:=		${_GCC_PREFIX}bin:${PATH}
CC=		${_GCC_PREFIX}bin/gcc
CPP=		${_GCC_PREFIX}bin/cpp
CXX=		${_GCC_PREFIX}bin/g++
F77=		${_GCC_PREFIX}bin/g77
PKG_FC:=	${F77}
.  endif
.else
.  if !empty(_IS_BUILTIN_GCC:M[yY][eE][sS])
_GCC_PATH!=	${TYPE} ${CC} | ${AWK} '{ print $$NF }'
PATH:=		${_GCC_PATH:H}:${PATH}
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
