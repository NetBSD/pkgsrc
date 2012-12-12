# $NetBSD: gcc.mk,v 1.130 2012/12/12 20:49:01 marino Exp $
#
# This is the compiler definition for the GNU Compiler Collection.
#
# User-settable variables:
#
# GCCBASE
#	If using a native GCC and the compiler is not in $PATH then
#	this should be set to the base installation directory.
#
# USE_NATIVE_GCC
#	When set to "yes", the native gcc is used, no matter which
#	compiler version a package requires.
#
# USE_PKGSRC_GCC
#	Force using the appropriate version of GCC from pkgsrc based on
#	GCC_REQD instead of the native compiler.
#
#	This should be disabled only for debugging.
#
# USE_PKGSRC_GCC_RUNTIME
#	When set to "yes", the runtime gcc libraries (libgcc, libstdc++
#	etc) will be used from pkgsrc rather than the native compiler.
#
# Package-settable variables:
#
# GCC_REQD
#	The minimum version of the GNU Compiler Collection that is
#	required to build this package. Setting this variable doesn't
#	change the compiler that is used for building packages. See
#	ONLY_FOR_COMPILER for that purpose. This is a list of version
#	numbers, of which the maximum version is the definitive one.
#
#	NOTE: Be conservative when setting GCC_REQD, as lang/gcc3 is
#	known not to build on some platforms, e.g. Darwin.  If gcc3 is
#	required, set GCC_REQD=3.0 so that we do not try to pull in
#	lang/gcc3 unnecessarily and have it fail.
#
# USE_GCC_RUNTIME
#	Packages which build shared libraries but do not use libtool to
#	do so should define this variable.  It is used to determine whether
#	the gcc runtime should be depended upon when a user has enabled
#	USE_PKGSRC_GCC_RUNTIME.
#
# System-defined variables:
#
# CC_VERSION
#	A string of the form "gcc-4.3.2"
#
# CC_VERSION_STRING
#	The same(?) as CC_VERSION. FIXME: What's the difference between
#	the two?
#
# Keywords: gcc
#

.if !defined(COMPILER_GCC_MK)
COMPILER_GCC_MK=	defined

_VARGROUPS+=	gcc
_USER_VARS.gcc=	USE_NATIVE_GCC USE_PKGSRC_GCC
_PKG_VARS.gcc=	GCC_REQD
_SYS_VARS.gcc=	CC_VERSION CC_VERSION_STRING LANGUAGES.gcc
_DEF_VARS.gcc=	\
	CCPATH CPPPATH CXXPATH \
	F77PATH FCPATH \
	ADAPATH GMKPATH GLKPATH GDBPATH CHPPATH GLSPATH GNTPATH PRPPATH \
	IMAKEOPTS \
	LDFLAGS \
	PKG_CC PKG_CPP PKG_CXX PKG_FC \
	PKG_ADA PKG_GMK PKG_GLK PKG_GDB PKG_CHP PKG_GLK PKG_GNT PKG_PRP \
	_CC _COMPILER_RPATH_FLAG _COMPILER_STRIP_VARS \
	_GCCBINDIR _GCC_ARCHDIR _GCC_BIN_PREFIX _GCC_CC \
	_GCC_CPP _GCC_CXX _GCC_DEPENDENCY _GCC_DEPENDS \
	_GCC_FC _GCC_LDFLAGS _GCC_LIBDIRS _GCC_PKG \
	_GCC_PKGBASE _GCC_PKGSRCDIR _GCC_PKG_SATISFIES_DEP \
	_GCC_PREFIX _GCC_REQD _GCC_STRICTEST_REQD _GCC_SUBPREFIX \
	_GCC_TEST_DEPENDS _GCC_NEEDS_A_FORTRAN _GCC_VARS _GCC_VERSION \
	_GCC_VERSION_STRING \
	_GCC_ADA _GCC_GMK _GCC_GLK _GCC_GDB _GCC_CHP _GCC_GLS _GCC_GNT _GCC_PRP \
	_IGNORE_GCC _IGNORE_GCC3CXX _IGNORE_GCC3F77 _IGNORE_GCC3OBJC \
	_IS_BUILTIN_GCC \
	_LANGUAGES.gcc \
	_LINKER_RPATH_FLAG \
	_NEED_GCC2 _NEED_GCC3 _NEED_GCC34 _NEED_GCC44 _NEED_NEWER_GCC \
	_PKGSRC_GCC_VERSION \
	_USE_GCC_SHLIB _USE_PKGSRC_GCC \
	_WRAP_EXTRA_ARGS.CC

.include "../../mk/bsd.prefs.mk"

USE_NATIVE_GCC?=	no
USE_PKGSRC_GCC?=	no
USE_PKGSRC_GCC_RUNTIME?=no

GCC_REQD+=	2.8.0

# gcc2 doesn't support c99 and amd64
.if !empty(USE_LANGUAGES:Mc99) || ${MACHINE_ARCH} == "x86_64"
GCC_REQD+=	3.0
.endif

# Only one compiler defined here supports Ada: lang/gcc-aux
# If the Ada language is requested, force lang/gcc-aux to be selected
.if !empty(USE_LANGUAGES:Mada)
GCC_REQD+=	20120614
.endif

# _GCC_DIST_VERSION is the highest version of GCC installed by the pkgsrc
# without the PKGREVISIONs.
#
.include "../../lang/gcc47/version.mk"
_GCC_DIST_VERSION:=	${GCC_DIST_VERSION}

# _GCC2_PATTERNS matches N s.t. N <= 2.95.3.
_GCC2_PATTERNS=	[0-1].* 2.[0-9] 2.[0-9].* 2.[1-8][0-9] 2.[1-8][0-9].*	\
		2.9[0-4] 2.9[0-4].* 2.95 2.95.[0-3]

# _GCC3_PATTERNS matches N s.t. 2.95.3 < N < 3.4.
_GCC3_PATTERNS=	2.95.[4-9]* 2.95.[1-9][0-9]* 2.9[6-9] 2.9[6-9].*	\
		2.[1-9][0-9][0-9]* 3.[0-3] 3.[0-3].*

# _GCC34_PATTERNS matches N s.t. 3.4 <= N < 4.
_GCC34_PATTERNS= 3.[4-9] 3.[4-9].* 3.[1-9][0-9]*

# _GCC44_PATTERNS matches N s.t. 4.4 <= N < 4.5.
_GCC44_PATTERNS= 4.4 4.4.*

# _GCC45_PATTERNS matches N s.t. 4.5 <= N < 4.6.
_GCC45_PATTERNS= 4.5 4.5.*

# _GCC46_PATTERNS matches N s.t. 4.6 <= N < 4.7.
_GCC46_PATTERNS= 4.6 4.6.*

# _GCC46_PATTERNS matches N s.t. 4.7 <= N.
_GCC47_PATTERNS= 4.[7-9] 4.[7-9].* 4.[1-9][0-9]* [4-9]*

# _GCC_AUX_PATTERNS matches 8-digit date YYYYMMDD*
_GCC_AUX_PATTERNS= 20[1-2][0-9][0-1][0-9][0-3][0-9]*

# _CC is the full path to the compiler named by ${CC} if it can be found.
.if !defined(_CC)
_CC:=	${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.  if !empty(GCCBASE) && exists(${GCCBASE}/bin)
_EXTRA_CC_DIRS=	${GCCBASE}/bin
.  endif
.  for _dir_ in ${_EXTRA_CC_DIRS} ${PATH:C/\:/ /g}
.    if empty(_CC:M/*)
.      if exists(${_dir_}/${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//})
_CC:=	${_dir_}/${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}
.      endif
.    endif
.  endfor
MAKEFLAGS+=	_CC=${_CC:Q}
.endif

.if !defined(_GCC_VERSION)
#
# FIXME: Ideally we'd use PKGSRC_SETENV here, but not enough of the tools
# infrastructure is loaded for SETENV to be defined when mk/compiler.mk is
# included first.  LC_ALL is required here for similar reasons, as ALL_ENV
# is not defined at this stage.
#
_GCC_VERSION_STRING!=	\
	( env LC_ALL=C ${_CC} -v 2>&1 | ${GREP} 'gcc version') 2>/dev/null || ${ECHO} 0
.  if !empty(_GCC_VERSION_STRING:Megcs*)
_GCC_VERSION=	2.8.1		# egcs is considered to be gcc-2.8.1.
.  elif !empty(DRAGONFLY_CCVER) && ${OPSYS} == "DragonFly"
_GCC_VERSION!= env CCVER=${DRAGONFLY_CCVER} ${_CC} -dumpversion
.  elif !empty(_GCC_VERSION_STRING:Mgcc*)
_GCC_VERSION!=	${_CC} -dumpversion
.  else
_GCC_VERSION=	0
.  endif
.endif
_GCC_PKG=	gcc-${_GCC_VERSION:C/-.*$//}

.if !empty(_CC:M${LOCALBASE}/*)
_IS_BUILTIN_GCC=	NO
GCC_REQD+=		${_GCC_VERSION}
.else
.  if !empty(_CC:M/*)
#
# GCC in older versions of Darwin report "Apple Computer ... based on gcc
# version ...", so we can't just grep for "^gcc".
#
.    if ${_GCC_VERSION} != "0"
_IS_BUILTIN_GCC=	YES
.    else
_IS_BUILTIN_GCC=	NO
.    endif
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
	if ${PKG_ADMIN} pmatch 'gcc>=${_vers_}' ${_pkg_} 2>/dev/null; then \
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
_NEED_GCC34?=	no
.for _pattern_ in ${_GCC34_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC34=	yes
.  endif
.endfor
_NEED_GCC44?=	no
.for _pattern_ in ${_GCC44_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC44=	yes
.  endif
.endfor
_NEED_GCC45?=	no
.for _pattern_ in ${_GCC45_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC45=	yes
.  endif
.endfor
_NEED_GCC46?=	no
.for _pattern_ in ${_GCC46_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC46=	yes
.  endif
.endfor
_NEED_GCC47?=	no
.for _pattern_ in ${_GCC47_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC47=	yes
.  endif
.endfor
_NEED_GCC_AUX?=	no
.for _pattern_ in ${_GCC_AUX_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
_NEED_GCC_AUX=	yes
_NEED_NEWER_GCC=NO
.  endif
.endfor
.if !empty(_NEED_GCC2:M[nN][oO]) && !empty(_NEED_GCC3:M[nN][oO]) && \
    !empty(_NEED_GCC34:M[nN][oO]) && !empty(_NEED_GCC44:M[nN][oO]) && \
    !empty(_NEED_GCC45:M[nN][oO]) && !empty(_NEED_GCC46:M[nN][oO]) && \
    !empty(_NEED_GCC47:M[nN][oO]) && !empty(_NEED_GCC_AUX:M[nN][oO])
_NEED_GCC47=	yes
.endif

# Assume by default that GCC will only provide a C compiler.
LANGUAGES.gcc?=	c
.if !empty(_NEED_GCC2:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 objc
.elif !empty(_NEED_GCC3:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 java objc
.elif !empty(_NEED_GCC34:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 objc
.elif !empty(_NEED_GCC44:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 java objc
.elif !empty(_NEED_GCC45:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 java objc
.elif !empty(_NEED_GCC46:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 java objc
.elif !empty(_NEED_GCC47:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC_AUX:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 objc ada
.endif
_LANGUAGES.gcc=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gcc+=	${LANGUAGES.gcc:M${_lang_}}
.endfor

.if !empty(USE_LANGUAGES:Mc99)
_WRAP_EXTRA_ARGS.CC+=	-std=gnu99
.endif

# GCC has this annoying behaviour where it advocates in a multi-line
# banner the use of "#include" over "#import" when including headers.
# This generates a huge number of warnings when building practically all
# Objective-C code where it is convention to use "#import".  Suppress
# the warning if we're building Objective-C code using GCC.
#
.if !empty(_LANGUAGES.gcc:Mobjc)
CFLAGS+=	-Wno-import
.endif

.if !empty(_NEED_GCC2:M[yY][eE][sS])
#
# We require gcc-2.x in the lang/gcc directory.
#
_GCC_PKGBASE=		gcc
.  if !empty(PKGPATH:Mlang/gcc)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc
_GCC_DEPENDENCY=	gcc>=${_GCC_REQD}:../../lang/gcc
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mobjc)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC3:M[yY][eE][sS])
#
# We require gcc-3.x in the lang/gcc3-* directories.
#
_GCC_PKGBASE=		gcc3-c
.  if !empty(PKGPATH:Mlang/gcc3-c)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc:Mc)
_GCC_PKGSRCDIR=		../../lang/gcc3-c
_GCC_DEPENDENCY=	gcc3-c>=${_GCC_REQD}:../../lang/gcc3-c
.  endif
.elif !empty(_NEED_GCC34:M[yY][eE][sS])
#
# We require gcc-3.4.x in the lang/gcc34 directory.
#
_GCC_PKGBASE=		gcc34
.  if !empty(PKGPATH:Mlang/gcc34)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc34
_GCC_DEPENDENCY=	gcc34>=${_GCC_REQD}:../../lang/gcc34
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mobjc)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC44:M[yY][eE][sS])
#
# We require gcc-4.4.x in the lang/gcc44 directory.
#
_GCC_PKGBASE=		gcc44
.  if !empty(PKGPATH:Mlang/gcc44)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc44
_GCC_DEPENDENCY=	gcc44>=${_GCC_REQD}:../../lang/gcc44
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mobjc)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC45:M[yY][eE][sS])
#
# We require gcc-4.5.x in the lang/gcc45 directory.
#
_GCC_PKGBASE=		gcc45
.  if !empty(PKGPATH:Mlang/gcc45)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc45
_GCC_DEPENDENCY=	gcc45>=${_GCC_REQD}:../../lang/gcc45
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mobjc)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC46:M[yY][eE][sS])
#
# We require gcc-4.6.x in the lang/gcc46 directory.
#
_GCC_PKGBASE=		gcc46
.  if !empty(PKGPATH:Mlang/gcc46)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc46
_GCC_DEPENDENCY=	gcc46>=${_GCC_REQD}:../../lang/gcc46
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mobjc)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC47:M[yY][eE][sS])
#
# We require gcc-4.7.x in the lang/gcc47 directory.
#
_GCC_PKGBASE=		gcc47
.  if !empty(PKGPATH:Mlang/gcc47)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc47
_GCC_DEPENDENCY=	gcc47>=${_GCC_REQD}:../../lang/gcc47
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC_AUX:M[yY][eE][sS])
#
# We require Ada-capable compiler in the lang/gcc-aux directory.
#
_GCC_PKGBASE=		gcc-aux
.  if !empty(PKGPATH:Mlang/gcc-aux)
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc-aux
_GCC_DEPENDENCY=	gcc-aux>=${_GCC_REQD}:../../lang/gcc-aux
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mada) || \
        !empty(_LANGUAGES.gcc:Mobjc)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.endif
_GCC_DEPENDS=		${_GCC_PKGBASE}>=${_GCC_REQD}

.if !empty(_NEED_GCC3:M[yY][eE][sS])
.  if !empty(PKGPATH:Mlang/gcc3-c++)
_IGNORE_GCC3CXX=	yes
MAKEFLAGS+=		_IGNORE_GCC3CXX=yes
.  endif
.  if !defined(_IGNORE_GCC3CXX) && !empty(_LANGUAGES.gcc:Mc++)
_GCC_PKGSRCDIR+=	../../lang/gcc3-c++
_GCC_DEPENDENCY+=	gcc3-c++>=${_GCC_REQD}:../../lang/gcc3-c++
_USE_GCC_SHLIB?=	yes
.  endif
.  if !empty(PKGPATH:Mlang/gcc3-f77)
_IGNORE_GCC3F77=	yes
MAKEFLAGS+=		_IGNORE_GCC3F77=yes
.  endif
.  if !defined(_IGNORE_GCC3F77) && (!empty(_LANGUAGES.gcc:Mfortran) || !empty(_LANGUAGES.gcc:Mfortran77))
_GCC_PKGSRCDIR+=	../../lang/gcc3-f77
_GCC_DEPENDENCY+=	gcc3-f77>=${_GCC_REQD}:../../lang/gcc3-f77
_USE_GCC_SHLIB?=	yes
.  endif
.  if !empty(PKGPATH:Mlang/gcc3-objc)
_IGNORE_GCC3OBJC=	yes
MAKEFLAGS+=		_IGNORE_GCC3OBJC=yes
.  endif
.  if !defined(_IGNORE_GCC3OBJC) && !empty(_LANGUAGES.gcc:Mobjc)
_GCC_PKGSRCDIR+=	../../lang/gcc3-objc
_GCC_DEPENDENCY+=	gcc3-objc>=${_GCC_REQD}:../../lang/gcc3-objc
_USE_GCC_SHLIB?=	yes
.  endif
.endif

# When not using the GNU linker, gcc will always link shared libraries against
# the shared version of libgcc, and so _USE_GCC_SHLIB needs to be enabled on
# platforms with non-GNU linkers, such as SunOS.
#
# However, we cannot simply do this by default as it will create circular
# dependencies in packages which are required to build gcc itself, and so we
# enable it based on USE_LIBTOOL for the majority of packages, and support
# USE_GCC_RUNTIME for packages which create shared libraries but do not use
# libtool to do so.
#
.if ${OPSYS} == "SunOS" && (defined(USE_LIBTOOL) || defined(USE_GCC_RUNTIME))
_USE_GCC_SHLIB= yes
.endif

.if !empty(USE_NATIVE_GCC:M[yY][eE][sS]) && !empty(_IS_BUILTIN_GCC:M[yY][eE][sS])
_USE_PKGSRC_GCC=	no
.elif !empty(USE_PKGSRC_GCC:M[yY][eE][sS])
# For environments where there is an external gcc too, but pkgsrc
# should use the pkgsrc one for consistency.
_USE_PKGSRC_GCC=	yes
.endif

.if defined(_IGNORE_GCC)
_USE_PKGSRC_GCC=	NO
.endif

.if !defined(_USE_PKGSRC_GCC)
_USE_PKGSRC_GCC=	YES
.  if !empty(_IS_BUILTIN_GCC:M[yY][eE][sS])
_GCC_TEST_DEPENDS=	gcc>=${_GCC_REQD}
_USE_PKGSRC_GCC!=	\
	if ${PKG_ADMIN} pmatch '${_GCC_TEST_DEPENDS}' ${_GCC_PKG} 2>/dev/null; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
.endif

# Check if any of the versions of GCC in pkgsrc can satisfy the _GCC_REQD
# requirement.
#
.if !defined(_NEED_NEWER_GCC)
_PKGSRC_GCC_VERSION=	${_GCC_PKGBASE}-${_GCC_DIST_VERSION}
_NEED_NEWER_GCC!=	\
	if ${PKG_ADMIN} pmatch '${_GCC_DEPENDS}' ${_PKGSRC_GCC_VERSION} 2>/dev/null; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
#MAKEFLAGS+=	_NEED_NEWER_GCC=${_NEED_NEWER_GCC}
.endif
.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS]) && \
    !empty(_NEED_NEWER_GCC:M[yY][eE][sS])
PKG_FAIL_REASON=	"Unable to satisfy dependency: ${_GCC_DEPENDS}"
.endif

# GNU ld option used to set the rpath
_LINKER_RPATH_FLAG=	-R

# GCC passes rpath directives to the linker using "-Wl,-R".
_COMPILER_RPATH_FLAG=	-Wl,${_LINKER_RPATH_FLAG}

.if !empty(MACHINE_ARCH:Mmips*)
_COMPILER_ABI_FLAG.32=	-mabi=n32	# ABI == "32" == "n32"
_COMPILER_ABI_FLAG.n32=	-mabi=n32
_COMPILER_ABI_FLAG.o32=	-mabi=32
_COMPILER_ABI_FLAG.64=	-mabi=64

.  if defined(ABI) && !empty(ABI)
MABIFLAG=	${_COMPILER_ABI_FLAG.${ABI}}
.  endif
.endif

.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
#
# Ensure that the correct rpath is passed to the linker if we need to
# link against gcc shared libs.
#
_GCC_SUBPREFIX!=	\
	if ${PKG_INFO} -qe ${_GCC_PKGBASE}; then			\
		${PKG_INFO} -f ${_GCC_PKGBASE} |			\
		${GREP} "File:.*bin/gcc" |				\
		${GREP} -v "/gcc[0-9][0-9]*-.*" |			\
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
		${DIRNAME} `${_GCC_PREFIX}bin/gcc ${MABIFLAG} -print-libgcc-file-name 2>/dev/null`; \
	else								\
		${ECHO} "_GCC_ARCHDIR_not_found";			\
	fi
.  if empty(_GCC_ARCHDIR:M*not_found*)
.    if defined(MABIFLAG) && !empty(MABIFLAG)
_GCC_PREFIX:=		${_GCC_ARCHDIR:H:H:H:H:H}/
_GCC_SUBPREFIX:=	${_GCC_ARCHDIR:H:H:H:H:H:T}/
.    else
_GCC_PREFIX:=		${_GCC_ARCHDIR:H:H:H:H}/
_GCC_SUBPREFIX:=	${_GCC_ARCHDIR:H:H:H:H:T}/
.    endif
.  endif
_GCC_LIBDIRS=	${_GCC_ARCHDIR} ${_GCC_PREFIX}lib
_GCC_LDFLAGS=	# empty
.  for _dir_ in ${_GCC_LIBDIRS:N*not_found*}
_GCC_LDFLAGS+=	-L${_dir_} ${COMPILER_RPATH_FLAG}${_dir_}
.  endfor
LDFLAGS+=	${_GCC_LDFLAGS}
.endif

# Point the variables that specify the compiler to the installed
# GCC executables.
#
_GCC_DIR=	${WRKDIR}/.gcc
_GCC_VARS=	# empty

.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
_GCCBINDIR=	${_GCC_PREFIX}bin
.elif !empty(_IS_BUILTIN_GCC:M[yY][eE][sS])
_GCCBINDIR=	${_CC:H}
.endif
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
_GCC_BIN_PREFIX=	${MACHINE_GNU_PLATFORM}-
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}gcc)
_GCC_VARS+=	CC
_GCC_CC=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gcc
_ALIASES.CC=	cc gcc
CCPATH=		${_GCCBINDIR}/${_GCC_BIN_PREFIX}gcc
PKG_CC:=	${_GCC_CC}
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}cpp)
_GCC_VARS+=	CPP
_GCC_CPP=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}cpp
_ALIASES.CPP=	cpp
CPPPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}cpp
PKG_CPP:=	${_GCC_CPP}
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}g++)
_GCC_VARS+=	CXX
_GCC_CXX=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}g++
_ALIASES.CXX=	c++ g++
CXXPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}g++
PKG_CXX:=	${_GCC_CXX}
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}g77)
_GCC_VARS+=	FC
_GCC_FC=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}g77
_ALIASES.FC=	f77 g77
FCPATH=		${_GCCBINDIR}/${_GCC_BIN_PREFIX}g77
F77PATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}g77
PKG_FC:=	${_GCC_FC}
PKGSRC_FORTRAN?=	g77
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}gfortran)
_GCC_VARS+=	FC
_GCC_FC=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gfortran
_ALIASES.FC=	gfortran
FCPATH=		${_GCCBINDIR}/${_GCC_BIN_PREFIX}gfortran
F77PATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gfortran
PKG_FC:=	${_GCC_FC}
PKGSRC_FORTRAN?=	gfortran
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}ada)
_GCC_VARS+=	ADA GMK GLK GBD CHP PRP GLS GNT
_GCC_ADA=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}ada
_GCC_GMK=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnatmake
_GCC_GLK=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnatlink
_GCC_GBD=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnatbind
_GCC_CHP=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnatchop
_GCC_PRP=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnatprep
_GCC_GLS=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnatls
_GCC_GNT=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gnat
_ALIASES.ADA=	ada
_ALIASES.GMK=	gnatmake
_ALIASES.GLK=	gnatlink
_ALIASES.GBD=	gnatbind
_ALIASES.CHP=	gnatchop
_ALIASES.PRP=	gnatprep
_ALIASES.GLS=	gnatls
_ALIASES.GNT=	gnat
ADAPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}ada
GMKPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatmake
GLKPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatlink
GBDPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatbind
CHPPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatchop
PRPPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatprep
GLSPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatls
GNTPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnat
PKG_ADA:=	${_GCC_ADA}
PKG_GMK:=	${_GCC_GMK}
PKG_GLK:=	${_GCC_GLK}
PKG_GBD:=	${_GCC_GBD}
PKG_CHP:=	${_GCC_CHP}
PKG_PRP:=	${_GCC_PRP}
PKG_GLS:=	${_GCC_GLS}
PKG_GNT:=	${_GCC_GNT}
PKGSRC_ADA?=	ada
PKGSRC_GMK?=	gnatmake
PKGSRC_GLK?=	gnatlink
PKGSRC_GBD?=	gnatbind
PKGSRC_CHP?=	gnatchop
PKGSRC_PRP?=	gnatprep
PKGSRC_GLS?=	gnatls
PKGSRC_GNT?=	gnat
.endif
_COMPILER_STRIP_VARS+=	${_GCC_VARS}

# Pass the required flags to imake to tell it we're using gcc on Solaris.
.if ${OPSYS} == "SunOS"
IMAKEOPTS+=	-DHasGcc2=YES -DHasGcc2ForCplusplus=YES
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
_COMPILER_ABI_FLAG.32=  -m32
_COMPILER_ABI_FLAG.64=  -m64
.endif

.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.  if exists(${CCPATH})
CC_VERSION_STRING!=	${CCPATH} -v 2>&1
CC_VERSION!=		\
	if ${CCPATH} -dumpversion > /dev/null 2>&1; then		\
		${ECHO} "gcc-`${CCPATH} -dumpversion`";			\
	else								\
		${ECHO} "gcc-${_GCC_REQD}";				\
	fi

.  else
CC_VERSION_STRING=	${CC_VERSION}
CC_VERSION=		gcc-${_GCC_REQD}
.  endif
.else
CC_VERSION_STRING=	${CC_VERSION}
CC_VERSION=		${_GCC_PKG}
.endif

# Prepend the path to the compiler to the PATH.
.if !empty(_LANGUAGES.gcc)
PREPEND_PATH+=	${_GCC_DIR}/bin
.endif

# Add the dependency on GCC.
.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
.  for _dir_ in ${_GCC_PKGSRCDIR}
.    include "${_dir_}/buildlink3.mk"
.  endfor
.endif

# Add dependency on GCC libraries if requested.
.if (defined(_USE_GCC_SHLIB) && !empty(_USE_GCC_SHLIB:M[Yy][Ee][Ss])) && !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
#  Special case packages which are themselves a dependency of gcc runtime.
.  if empty(PKGPATH:Mdevel/libtool-base) && empty(PKGPATH:Mdevel/binutils)
.    include "../../lang/gcc47-libs/buildlink3.mk"
.  endif
.endif

.for _var_ in ${_GCC_VARS}
.  if !target(${_GCC_${_var_}})
override-tools: ${_GCC_${_var_}}
${_GCC_${_var_}}:
	${RUN}${MKDIR} ${.TARGET:H}
.    if !empty(COMPILER_USE_SYMLINKS:M[Yy][Ee][Ss])
	${RUN}${RM} -f ${.TARGET}
	${RUN}${LN} -s ${_GCCBINDIR}/${.TARGET:T} ${.TARGET}
.    else
	${RUN}					\
	(${ECHO} '#!${TOOLS_SHELL}';					\
	 ${ECHO} 'exec ${_GCCBINDIR}/${.TARGET:T} "$$@"';		\
	) > ${.TARGET}
	${RUN}${CHMOD} +x ${.TARGET}
.    endif
.    for _alias_ in ${_ALIASES.${_var_}:S/^/${.TARGET:H}\//}
	${RUN}					\
	if [ ! -x "${_alias_}" ]; then					\
		${LN} -f -s ${.TARGET:T} ${_alias_};			\
	fi
.    endfor
.  endif
.endfor

# On older NetBSD systems and where the Fortran compiler doesn't exist,
# force the use of f2c-f77 or some other fortran.
#
.if !empty(USE_LANGUAGES:Mfortran)
PKGSRC_FORTRAN?=g95
.endif
#.if !empty(USE_LANGUAGES:Mfortran77)
PKGSRC_FORTRAN?=f2c
#.endif

_GCC_NEEDS_A_FORTRAN=	no
.if empty(_USE_PKGSRC_GCC:M[yY][eE][sS]) && !exists(${FCPATH})
_GCC_NEEDS_A_FORTRAN=	yes
.else
.  for _pattern_ in 0.* 1.[0-4] 1.[0-4].*
.    if !empty(MACHINE_PLATFORM:MNetBSD-${_pattern_}-*)
_GCC_NEEDS_A_FORTRAN=	yes
.    endif
.  endfor
.endif
.if !empty(_GCC_NEEDS_A_FORTRAN:M[yY][eE][sS])
.  include "../../mk/compiler/${PKGSRC_FORTRAN}.mk"
.endif

.endif	# COMPILER_GCC_MK
