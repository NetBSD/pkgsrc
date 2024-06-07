# $NetBSD: gcc.mk,v 1.278 2024/06/07 11:13:04 gdt Exp $
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
#	When set to "yes", use an appropriate version of GCC from
#	pkgsrc based on GCC_REQD instead of the native compiler.
#
# USE_PKGSRC_GCC_RUNTIME
#	When set to "yes", the runtime gcc libraries (libgcc, libstdc++
#	etc) will be used from pkgsrc rather than the native compiler.
#
# GCC_VERSION_SUFFIX
#	Optional suffix for GCC binaries, i.e. if the installed names are like
#	/usr/bin/g++-5, /usr/bin/gcc-5 etc.

# Package-settable variables:
#
# GCC_REQD
#	The minimum version of the GNU Compiler Collection that is
#	required to build this package. Setting this variable doesn't
#	change the compiler that is used for building packages. See
#	ONLY_FOR_COMPILER for that purpose. This is a list of version
#	numbers, of which the maximum version is the definitive one.
#
#	This variable can also be set by the user when USE_PKGSRC_GCC
#	is in effect to ensure that a specific compiler is used for
#	packages which do not specify a higher version.
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
_USER_VARS.gcc=	\
	USE_NATIVE_GCC USE_PKGSRC_GCC USE_PKGSRC_GCC_RUNTIME \
	GCCBASE GCC_VERSION_SUFFIX \
	TOOLS_USE_CROSS_COMPILE \
	PKGSRC_USE_FORTIFY PKGSRC_USE_RELRO PKGSRC_USE_SSP \
	COMPILER_USE_SYMLINKS CC
_PKG_VARS.gcc=	\
	GCC_REQD USE_GCC_RUNTIME USE_LANGUAGES
_SYS_VARS.gcc=	\
	CC_VERSION CC_VERSION_STRING LANGUAGES.gcc \
	CCPATH CPPPATH CXXPATH F77PATH FCPATH \
	PKG_CC PKG_CPP PKG_CXX PKG_FC FC PKGSRC_FORTRAN \
	ADAPATH GMKPATH GLKPATH GBDPATH CHPPATH GLSPATH GNTPATH PRPPATH
_DEF_VARS.gcc=	\
	MAKEFLAGS IMAKEOPTS \
	CFLAGS LDFLAGS \
	PREPEND_PATH \
	COMPILER_INCLUDE_DIRS COMPILER_LIB_DIRS \
	CWRAPPERS_APPEND.cc CWRAPPERS_APPEND.cxx CWRAPPERS_APPEND.ld \
	PKG_ADA PKG_GMK PKG_GLK PKG_GBD PKG_CHP PKG_GNT PKG_GLS PKG_PRP \
	PKGSRC_ADA PKGSRC_GMK PKGSRC_GLK PKGSRC_GBD PKGSRC_CHP PKGSRC_GNT PKGSRC_GLS PKGSRC_PRP \
	_CC _COMPILER_RPATH_FLAG _COMPILER_STRIP_VARS \
	_GCCBINDIR _GCC_ARCHDIR _GCC_BIN_PREFIX _GCC_CFLAGS \
	_GCC_CC _GCC_CPP _GCC_CXX _GCC_DEPENDENCY _GCC_DEPENDS \
	_GCC_DIST_NAME _GCC_DIST_VERSION \
	_GCC_FC _GCC_LDFLAGS _GCC_LIBDIRS _GCC_PKG \
	_GCC_PKGBASE _GCC_PKGSRCDIR _GCC_PKG_SATISFIES_DEP \
	_GCC_PREFIX _GCC_REQD _GCC_STRICTEST_REQD _GCC_SUBPREFIX \
	_GCC_TEST_DEPENDS _GCC_NEEDS_A_FORTRAN _GCC_VARS _GCC_VERSION \
	_GCC_VERSION_STRING \
	_GCC_ADA _GCC_GMK _GCC_GLK _GCC_GBD _GCC_CHP _GCC_GLS _GCC_GNT _GCC_PRP \
	_IGNORE_GCC \
	_IS_BUILTIN_GCC \
	_LANGUAGES.gcc \
	_LINKER_RPATH_FLAG \
	_NEED_GCC6 _NEED_GCC7 _NEED_GCC8 _NEED_GCC9 \
	_NEED_GCC10 _NEED_GCC12 _NEED_GCC13 \
	_NEED_GCC_AUX _NEED_NEWER_GCC \
	_NEED_GCC6_AUX _NEED_GCC10_AUX _NEED_GCC13_GNAT \
	_PKGSRC_GCC_VERSION \
	_USE_GCC_SHLIB _USE_PKGSRC_GCC \
	_WRAP_EXTRA_ARGS.CC \
	_EXTRA_CC_DIRS \
	_C_STD_VERSIONS \
	${_C_STD_VERSIONS:@std@_C_STD_FLAG.${std}@} \
	_CXX_STD_VERSIONS \
	${_CXX_STD_VERSIONS:@std@_CXX_STD_FLAG.${std}@} \
	_MKPIE_CFLAGS.gcc _MKPIE_LDFLAGS \
	_FORTIFY_CFLAGS _RELRO_LDFLAGS _STACK_CHECK_CFLAGS \
	_CTF_CFLAGS \
	_GCC_DIR \
	_ALIASES.CC _ALIASES.CPP _ALIASES.CXX _ALIASES.FC \
	_ALIASES.ADA _ALIASES.GMK _ALIASES.GLK _ALIASES.GBD \
	_ALIASES.CHP _ALIASES.PRP _ALIASES.GLS _ALIASES.GNT \
	_COMPILER_ABI_FLAG.32 _COMPILER_ABI_FLAG.64 \
	_COMPILER_ABI_FLAG.n32 _COMPILER_ABI_FLAG.o32 \
	_SSP_CFLAGS \
	_CXX_STD_FLAG.c++03 _CXX_STD_FLAG.gnu++03
_USE_VARS.gcc=	\
	MACHINE_ARCH PATH DRAGONFLY_CCVER OPSYS TOOLBASE \
	USE_LIBTOOL \
	LIBABISUFFIX \
	COMPILER_RPATH_FLAG \
	MACHINE_GNU_PLATFORM \
	WRKDIR MACHINE_PLATFORM PKGPATH \
	_PKGSRC_MKPIE _PKGSRC_MKREPRO _MKREPRO_CFLAGS.gcc \
	_PKGSRC_USE_FORTIFY _PKGSRC_USE_RELRO _PKGSRC_USE_STACK_CHECK \
	_OPSYS_INCLUDE_DIRS _OPSYS_LIB_DIRS
_IGN_VARS.gcc=	\
	_GCC6_PATTERNS _GCC7_PATTERNS _GCC8_PATTERNS _GCC9_PATTERNS \
	_GCC10_PATTERNS _GCC12_PATTERNS _GCC13_PATTERNS _GCC_AUX_PATTERNS
_LISTED_VARS.gcc= \
	MAKEFLAGS IMAKEOPTS LDFLAGS PREPEND_PATH
.include "../../mk/bsd.prefs.mk"

USE_NATIVE_GCC?=	no
USE_PKGSRC_GCC?=	no
USE_PKGSRC_GCC_RUNTIME?=no

#
# Each successive GCC_REQD has an associated cost below when executing
# pkg_admin to determine if it's suitable, so only add these incredibly
# old versions if we haven't already set one.
#
.if !defined(GCC_REQD)
.  if !empty(USE_LANGUAGES:Mc99) || ${MACHINE_ARCH} == "x86_64"
GCC_REQD+=	3.0
.  else
GCC_REQD+=	2.8.0
.  endif
.endif

.include "../../mk/compiler/gcc-style-args.mk"

#
# Most of the time, GCC adds support for features of new C and C++
# standards incrementally; we define USE_CXX_FEATURES=c++XX as
# intending to require a compiler that fully supports the standard.
#
# We of course only choose versions in pkgsrc, and tend towards a gcc
# version included in a NetBSD release, because those are known to
# work well, and because it is simpler to limit selection to fewer
# versions.  This tendency is much stronger for C++ versions, and less
# so for c11.
#
# Thus we tend to:
#   - gcc 4.8, in NetBSD 7, CentOS 7
#   - gcc 5, in NetBSD 8
#   - gcc 7, in NetBSD 9
#   - gcc 10, in NetBSD 10
#
# Other systems have different versions, and we note a few:
#
#  - gcc 8, in Enterprise Linux 8
#
# Resources:
# https://gcc.gnu.org/projects/cxx-status.html
# https://gcc.gnu.org/wiki/C11Status
# https://gcc.gnu.org/c99status.html
#

.if !empty(USE_CXX_FEATURES:Mc++23)
# gcc documents that 14 is required.

# \todo Change to 14 or justify.
GCC_REQD+=	12
.endif

.if !empty(USE_CXX_FEATURES:Mc++20)
# gcc documents that 11 is required, with a few perhaps-obscure
# features requiring 12.

# We hope that it remains OK for most C++20 in the future...
# \todo Change to 11 or justify.
GCC_REQD+=	10
.endif

.if !empty(USE_CXX_FEATURES:Mc++17)
# gcc documents that 7 is required, except for a perhaps-obscure
# template feature.  However, <charconv> is part of c++17 and that
# requires gcc 8.

GCC_REQD+=	7
# \todo Change to 8 (<charconv> is not so odd) or justify.
.endif

.if !empty(USE_CXX_FEATURES:Mc++14)
# gcc documents that 5 is required.
GCC_REQD+=	5
.endif

.if !empty(USE_CXX_FEATURES:Mc++11)
# gcc documents that 4.8.1 is required.  (In addition, versions before
# 4.7 do not accept -std=c++11 and are thus not acceptable.)
GCC_REQD+=	4.8
.endif

.if !empty(USE_CXX_FEATURES:Mhas_include) || \
    !empty(USE_CC_FEATURES:Mhas_include)
GCC_REQD+=	5
.endif

.if !empty(USE_CC_FEATURES:Mc99)
GCC_REQD+=	3
.endif

# 4.9 supports c11; don't reject it by rounding up to 5
.if !empty(USE_CC_FEATURES:Mc11)
GCC_REQD+=	4.9
.endif

.if !empty(USE_CC_FEATURES:Mc17)
# See http://mail-index.netbsd.org/pkgsrc-users/2024/01/02/msg038697.html
# Actually gcc-9.x is enough, but it is not in any NetBSD
# base system, thus for convenience
GCC_REQD+=	10.0
.endif

# Don't round to gcc 5.
.if !empty(USE_CXX_FEATURES:Munique_ptr)
GCC_REQD+=	4.9
.endif

# Don't round to gcc 5.
.if !empty(USE_CXX_FEATURES:Mregex)
GCC_REQD+=	4.9
.endif

.if !empty(USE_CXX_FEATURES:Mput_time)
GCC_REQD+=	5
.endif

.if !empty(USE_CXX_FEATURES:Mis_trivially_copy_constructible)
GCC_REQD+=	5
.endif

.if !empty(USE_CXX_FEATURES:Mfilesystem)
# While GCC 7 supports filesystem under an experimental header, this
# is not part of GCC 7 as included in NetBSD 9.
#
# GCC 8 supports filesystem with explicit linking to the libstdc++fs
# library, which many packages do not do.
GCC_REQD+=	10
.endif

.if !empty(USE_CXX_FEATURES:Mparallelism_ts)
GCC_REQD+=	10
.endif

# Don't round to gcc10.
.if !empty(USE_CXX_FEATURES:Mcharconv)
GCC_REQD+=	8
.endif

# If the Ada language is requested, force use of aux/gnat comilers
_NEED_GCC_AUX?=no
.if !empty(USE_LANGUAGES:Mada)
_NEED_GCC_AUX=yes
.endif

# _GCC_DIST_VERSION is the highest version of GCC installed by the pkgsrc
# without the PKGREVISIONs.
_GCC_DIST_NAME:=	gcc13
.include "../../lang/${_GCC_DIST_NAME}/version.mk"
_GCC_DIST_VERSION:=	${${_GCC_DIST_NAME:tu}_DIST_VERSION}

# _GCC6_PATTERNS matches N s.t. N < 7.
_GCC6_PATTERNS= 5 6 [0-6].*

# _GCC7_PATTERNS matches N s.t. 7.0 <= N < 8.
_GCC7_PATTERNS= 7 7.*

# _GCC8_PATTERNS matches N s.t. 8.0 <= N < 9.
_GCC8_PATTERNS= 8 8.*

# _GCC9_PATTERNS matches N s.t. 9.0 <= N < 10.
_GCC9_PATTERNS= 9 9.*

# _GCC10_PATTERNS matches N s.t. 10.0 <= N < 11.
_GCC10_PATTERNS= 10 10.*

# _GCC12_PATTERNS matches N s.t. 12.0 <= N < 13.
# gcc 11.x is not packaged, so depend on gcc12 in that case too
_GCC12_PATTERNS= 11 11.* 12 12.*

# _GCC13_PATTERNS matches N s.t. 13.0 <= N < 14.
_GCC13_PATTERNS= 13 13.*

# _GCC_AUX_PATTERNS matches 8-digit date YYYYMMDD*
_GCC_AUX_PATTERNS= 20[1-2][0-9][0-1][0-9][0-3][0-9]*

# Override the default from sys.mk if necessary.
.if ${CC} == cc && ${GCCBASE:U} && !exists(${GCCBASE}/bin/${CC}) && exists(${GCCBASE}/bin/gcc)
CC=	gcc
.endif

# _CC is the full path to the compiler named by ${CC} if it can be found.
.if !defined(_CC)
_CC:=	${CC:[1]}
.  if !empty(GCCBASE) && exists(${GCCBASE}/bin)
_EXTRA_CC_DIRS=	${GCCBASE}/bin
.  endif
.  for _dir_ in ${_EXTRA_CC_DIRS} ${PATH:C/\:/ /g}
.    if empty(_CC:M/*)
.      if exists(${_dir_}/${CC:[1]})
_CC:=	${_dir_}/${CC:[1]}
.      endif
.    endif
.  endfor
.  if ${TOOLS_USE_CROSS_COMPILE:tl} == "no"
# Pass along _CC only if we're working on native packages -- don't pass
# the cross-compiler on to submakes for building native packages.
MAKEFLAGS+=	_CC=${_CC:Q}
.  endif
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

.if !empty(_GCC_VERSION:M[23].*) || !empty(_GCC_VERSION:M4.[01].*)
# A lot of packages attempt to do this as a workaround for a
# well-intentioned default in XCode 12+, but it's a common cause of
# build failures on old versions of Darwin which use gcc and don't
# understand this syntax.
#
# Note that pkgsrc also sets this flag itself for Darwin+clang.
BUILDLINK_TRANSFORM+=	rm:-Wno-error=implicit-function-declaration
BUILDLINK_TRANSFORM+=	rm:-Wno-error=sign-conversion
.endif

.if !empty(_GCC_VERSION:M[23].*) || !empty(_GCC_VERSION:M4.[01234].*)
# Added in GCC 4.5
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-result
.endif

.if !empty(_GCC_VERSION:M[23].*) || !empty(_GCC_VERSION:M4.[012].*)
# Added in GCC 4.3
BUILDLINK_TRANSFORM+=	rm:-Wvla
.endif

.if !empty(_GCC_VERSION:M[23].*) || !empty(_GCC_VERSION:M4.0.*)
# Added in GCC 4.3
BUILDLINK_TRANSFORM+=	rm:-Wc++-compat
BUILDLINK_TRANSFORM+=	rm:-Wno-c++-compat
.endif

.if !empty(_GCC_VERSION:M[23456].*)
# Added in GCC 7
BUILDLINK_TRANSFORM+=	rm:-Wimplicit-fallthrough
BUILDLINK_TRANSFORM+=	rm:-Wno-implicit-fallthrough
.endif

.if !empty(_GCC_VERSION:M3.*) || !empty(_GCC_VERSION:M4.[0-7].*)
# Added in GCC 4.8
BUILDLINK_TRANSFORM+=	opt:-std=c++03:-std=c++98
BUILDLINK_TRANSFORM+=	opt:-std=gnu++03:-std=gnu++98
.endif

.if !empty(_GCC_VERSION:M[23].*) || !empty(_GCC_VERSION:M4.[0-8].*)
COMPILER_HAS_C11?=	no
.else
COMPILER_HAS_C11?=	yes
.endif

.for _version_ in ${_C_STD_VERSIONS}
_C_STD_FLAG.${_version_}?=	-std=${_version_}
.endfor
# XXX: pkgsrc historically hardcoded c99=gnu99 so we retain that for now, but
# we should look at removing this and be explicit in packages where required.
_C_STD_FLAG.c99=	-std=gnu99

.for _version_ in ${_CXX_STD_VERSIONS}
_CXX_STD_FLAG.${_version_}?=	-std=${_version_}
.endfor

.if !empty(_CC:M${TOOLBASE}/*)
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

# Determine which GCC version is required by examining _GCC_REQD.
_NEED_GCC6?=	no
.for _pattern_ in ${_GCC6_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
# XXX this won't work without adjustments elsewhere because of how
# _GCC_REQD is processed.
#.    if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 089937
#USE_PKGSRC_GCC=		yes
#USE_PKGSRC_GCC_RUNTIME=	yes
#.    endif
_NEED_GCC6=	yes
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 6 to build"
.    endif
.  endif
.endfor
_NEED_GCC7?=	no
.for _pattern_ in ${_GCC7_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
.    if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 089937
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.    endif
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 7 to build"
.    endif
_NEED_GCC7=	yes
.  endif
.endfor
_NEED_GCC8?=	no
.for _pattern_ in ${_GCC8_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
.    if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099917
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.    endif
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 8 to build"
.    endif
_NEED_GCC8=	yes
.  endif
.endfor
_NEED_GCC9?=	no
.for _pattern_ in ${_GCC9_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
.    if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099976
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.    endif
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 9 to build"
.    endif
_NEED_GCC9=	yes
.  endif
.endfor
_NEED_GCC10?=	no
.for _pattern_ in ${_GCC10_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
.    if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099982
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.    endif
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 10 to build"
.    endif
_NEED_GCC10=	yes
.  endif
.endfor
_NEED_GCC12?=	no
.for _pattern_ in ${_GCC12_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
# XXX: pin to a version when NetBSD switches to gcc12
.    if ${OPSYS} == "NetBSD"
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.    endif
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 12 to build"
.    endif
_NEED_GCC12=	yes
.  endif
.endfor
_NEED_GCC13?=	no
.for _pattern_ in ${_GCC13_PATTERNS}
.  if !empty(_GCC_REQD:M${_pattern_})
# XXX: pin to a version when NetBSD switches to gcc13
.    if ${OPSYS} == "NetBSD"
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.    endif
.    if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gcc 13 to build"
.    endif
_NEED_GCC13=	yes
.  endif
.endfor
# AUX patterns really don't work starting from gcc10-aux
#_NEED_GCC_AUX?=	no
#.for _pattern_ in ${_GCC_AUX_PATTERNS}
#.  if !empty(_GCC_REQD:M${_pattern_})
#_NEED_GCC_AUX=	yes
#_NEED_NEWER_GCC=NO
#.  endif
#.endfor
.if !empty(_NEED_GCC6:M[nN][oO]) && !empty(_NEED_GCC7:M[nN][oO]) && \
    !empty(_NEED_GCC8:M[nN][oO]) && !empty(_NEED_GCC9:M[nN][oO]) && \
    !empty(_NEED_GCC10:M[nN][oO]) && !empty(_NEED_GCC12:M[nN][oO]) && \
    !empty(_NEED_GCC13:M[nN][oO]) && !empty(_NEED_GCC_AUX:M[nN][oO])
_NEED_GCC8=	yes
.endif

# April 2022: GCC below 10 from pkgsrc is broken on 32-bit arm NetBSD.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-earm*) && \
    ${OPSYS_VERSION} < 099900 && \
    (${_NEED_GCC8:tl} == "yes" || ${_NEED_GCC9:tl} == "yes")
_NEED_GCC6=	no
_NEED_GCC7=	no
_NEED_GCC8=	no
_NEED_GCC9=	no
_NEED_GCC10=	yes
_NEED_GCC12=	yes
_NEED_GCC13=	yes
.endif

# We have fixed set of Ada compilers and languages them provided. So we try to find best possible variant
_NEED_GCC6_AUX?=no
_NEED_GCC10_AUX?=no
_NEED_GCC13_GNAT?=no
.if ${_NEED_GCC_AUX:tl} == "yes"
USE_PKGSRC_GCC=yes
USE_PKGSRC_GCC_RUNTIME=no
.  if ${ALLOW_NEWER_COMPILER:tl} != "yes"
PKG_FAIL_REASON+=	"Package requires at least gnat 13 to build"
.  endif
_NEED_GCC13_GNAT=yes
.  if empty(USE_ADA_FEATURES:Mada2022)
_NEED_GCC10_AUX=yes
_NEED_GCC6_AUX=yes
.  endif
.  if !empty(USE_LANGUAGES:Mfortran) || !empty(USE_LANGUAGES:Mfortran77)
.     if ${_NEED_GCC10_AUX:tl} == "yes"
_NEED_GCC6_AUX=no
_NEED_GCC13_GNAT=no
.     else
PKG_FAIL_REASON+=	"Package requires fortran compiler"
.     endif
.  endif
.  if ${_NEED_GCC6_AUX:tl} == "yes" && ${_NEED_GCC6:tl} != "yes"
_NEED_GCC6_AUX=no
.  endif
.  if ${_NEED_GCC10_AUX:tl} == "yes" && ${_NEED_GCC10:tl} != "yes"
_NEED_GCC10_AUX=no
.  endif
.  if ${_NEED_GCC13_GNAT:tl} == "yes" && ${_NEED_GCC13:tl} != "yes"
_NEED_GCC13_GNAT=no
.  endif
.  if !empty(USE_LANGUAGES:Mobjc)
_NEED_GCC6_AUX=no
_NEED_GCC10_AUX=no
_NEED_GCC13_GNAT=no
PKG_FAIL_REASON+=	"Package requires objc compiler"
.  endif
.  if !empty(USE_LANGUAGES:Mobj-c++)
_NEED_GCC6_AUX=no
_NEED_GCC10_AUX=no
_NEED_GCC13_GNAT=no
PKG_FAIL_REASON+=	"Package requires obj-c++ compiler"
.  endif
.  if !empty(USE_LANGUAGES:Mgo)
_NEED_GCC6_AUX=no
_NEED_GCC10_AUX=no
_NEED_GCC13_GNAT=no
PKG_FAIL_REASON+=	"Package requires go compiler"
.  endif
.  if !empty(USE_LANGUAGES:Mjava)
_NEED_GCC6_AUX=no
_NEED_GCC10_AUX=no
_NEED_GCC13_GNAT=no
PKG_FAIL_REASON+=	"Package requires java compiler"
.  endif
_NEED_GCC6=no
_NEED_GCC7=no
_NEED_GCC8=no
_NEED_GCC9=no
_NEED_GCC10=no
_NEED_GCC12=no
_NEED_GCC13=no
.  if ${_NEED_GCC13_GNAT:tl} == "yes"
_NEED_GCC6_AUX=no
_NEED_GCC10_AUX=no
.  elif ${_NEED_GCC10_AUX:tl} == "yes"
_NEED_GCC6_AUX=no
.  endif
.endif

# Assume by default that GCC will only provide a C compiler.
LANGUAGES.gcc?=	c
.if !empty(_NEED_GCC6:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC7:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC8:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC9:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC10:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC12:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
.elif !empty(_NEED_GCC13:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 go java objc obj-c++
#.elif !empty(_NEED_GCC_AUX:M[yY][eE][sS])
#LANGUAGES.gcc=	c c++ fortran fortran77 objc ada
.elif !empty(_NEED_GCC6_AUX:M[yY][eE][sS])
# gcc6-aux doesn't provide some languages
LANGUAGES.gcc=	c c++ ada
.elif !empty(_NEED_GCC10_AUX:M[yY][eE][sS])
LANGUAGES.gcc=	c c++ fortran fortran77 ada
.elif !empty(_NEED_GCC13_GNAT:M[yY][eE][sS])
LANGUAGES.gcc=c c++ ada
.endif
_LANGUAGES.gcc=		# empty
.for _lang_ in ${USE_LANGUAGES}
_LANGUAGES.gcc+=	${LANGUAGES.gcc:M${_lang_}}
.endfor

.if ${_PKGSRC_USE_STACK_CHECK} == "yes"
_STACK_CHECK_CFLAGS=	-fstack-check
_GCC_CFLAGS+=		${_STACK_CHECK_CFLAGS}
.elif ${_PKGSRC_USE_STACK_CHECK} == "stack-clash"
_STACK_CHECK_CFLAGS=	-fstack-clash-protection
_GCC_CFLAGS+=		${_STACK_CHECK_CFLAGS}
.endif

.if ${_PKGSRC_MKPIE} == "yes"
_MKPIE_FCFLAGS=		-fPIC
.  if ${PKGSRC_OVERRIDE_MKPIE:tl} == "no"
_GCC_FCFLAGS+=		${_MKPIE_FCFLAGS}
.  endif
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

CFLAGS+=	${_GCC_CFLAGS}
FCFLAGS+=	${_GCC_FCFLAGS}

.if !empty(_NEED_GCC6:M[yY][eE][sS])
#
# We require gcc-6.x in the lang/gcc6-* directory.
#
_GCC_PKGBASE=		gcc6
.  if ${PKGPATH} == lang/gcc6
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc6
_GCC_DEPENDENCY=	gcc6>=${_GCC_REQD}:../../lang/gcc6
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC7:M[yY][eE][sS])
#
# We require gcc-7.x in the lang/gcc7-* directory.
#
_GCC_PKGBASE=		gcc7
.  if ${PKGPATH} == lang/gcc7
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc7
_GCC_DEPENDENCY=	gcc7>=${_GCC_REQD}:../../lang/gcc7
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC8:M[yY][eE][sS])
#
# We require gcc-8.x in the lang/gcc8-* directory.
#
_GCC_PKGBASE=		gcc8
.  if ${PKGPATH} == lang/gcc8
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc8
_GCC_DEPENDENCY=	gcc8>=${_GCC_REQD}:../../lang/gcc8
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC9:M[yY][eE][sS])
#
# We require gcc-9.x in the lang/gcc9-* directory.
#
_GCC_PKGBASE=		gcc9
.  if ${PKGPATH} == lang/gcc9
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc9
_GCC_DEPENDENCY=	gcc9>=${_GCC_REQD}:../../lang/gcc9
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC10:M[yY][eE][sS])
#
# We require gcc-10.x in the lang/gcc10-* directory.
#
_GCC_PKGBASE=		gcc10
.  if ${PKGPATH} == lang/gcc10
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc10
_GCC_DEPENDENCY=	gcc10>=${_GCC_REQD}:../../lang/gcc10
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC12:M[yY][eE][sS])
#
# We require gcc-12.x in the lang/gcc12-* directory.
#
_GCC_PKGBASE=		gcc12
.  if ${PKGPATH} == lang/gcc12
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc12
_GCC_DEPENDENCY=	gcc12>=${_GCC_REQD}:../../lang/gcc12
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC13:M[yY][eE][sS])
#
# We require gcc-13.x in the lang/gcc13-* directory.
#
_GCC_PKGBASE=		gcc13
.  if ${PKGPATH} == lang/gcc13
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc13
_GCC_DEPENDENCY=	gcc13>=${_GCC_REQD}:../../lang/gcc13
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mgo) || \
        !empty(_LANGUAGES.gcc:Mobjc) || \
        !empty(_LANGUAGES.gcc:Mobj-c++)
_USE_GCC_SHLIB?=	yes
.    endif
.  endif
.elif !empty(_NEED_GCC6_AUX:M[yY][eE][sS])
#
# We require Ada-capable compiler in the lang/gcc6-aux directory.
#
_GCC_PKGBASE=		gcc6-aux
.  if ${PKGPATH} == lang/gcc6-aux
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc6-aux
_GCC_DEPENDENCY=	gcc6-aux>=${_GCC_REQD}:../../lang/gcc6-aux
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mada)
_USE_GCC_SHLIB?=	no
.    endif
.  endif
.elif !empty(_NEED_GCC10_AUX:M[yY][eE][sS])
#
# We require Ada-capable compiler in the lang/gcc10-aux directory.
#
_GCC_PKGBASE=		gcc10-aux
.  if ${PKGPATH} == lang/gcc10-aux
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc10-aux
_GCC_DEPENDENCY=	gcc10-aux>=${_GCC_REQD}:../../lang/gcc10-aux
.    if !empty(_LANGUAGES.gcc:Mc++) || \
        !empty(_LANGUAGES.gcc:Mfortran) || \
        !empty(_LANGUAGES.gcc:Mfortran77) || \
        !empty(_LANGUAGES.gcc:Mada)
_USE_GCC_SHLIB?=	no
.    endif
.  endif
.elif !empty(_NEED_GCC13_GNAT:M[yY][eE][sS])
#
# We require Ada-capable compiler in the lang/gcc13-gnat directory.
#
_GCC_PKGBASE=		gcc13-gnat
.  if ${PKGPATH} == lang/gcc13-gnat
_IGNORE_GCC=		yes
MAKEFLAGS+=		_IGNORE_GCC=yes
.  endif
.  if !defined(_IGNORE_GCC) && !empty(_LANGUAGES.gcc)
_GCC_PKGSRCDIR=		../../lang/gcc13-gnat
_GCC_DEPENDENCY=	gcc13-gnat>=${_GCC_REQD}:../../lang/gcc13-gnat
_USE_GCC_SHLIB?=	no
.  endif
.endif
_GCC_DEPENDS=		${_GCC_PKGBASE}>=${_GCC_REQD}

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
.if (${OPSYS} == "Darwin" || ${OPSYS} == "SunOS") && \
    (defined(USE_LIBTOOL) || defined(USE_GCC_RUNTIME))
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
PKG_FAIL_REASON+=	"Unable to satisfy dependency: ${_GCC_DEPENDS}"
.endif

.if !empty(_USE_PKGSRC_GCC:M[yY][eE][sS])
#
# Ensure that the correct rpath is passed to the linker if we need to
# link against gcc shared libs.
#
# XXX cross-compilation -- is this TOOLBASE or LOCALBASE?
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
		${DIRNAME} `${_GCC_PREFIX}bin/gcc -print-libgcc-file-name 2>/dev/null`; \
	else								\
		${ECHO} "_GCC_ARCHDIR_not_found";			\
	fi
_GCC_LIBDIRS=	${_GCC_ARCHDIR}
.  if empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
_GCC_LIBDIRS+=	${_GCC_PREFIX}lib${LIBABISUFFIX}
.  endif
_GCC_LDFLAGS=	# empty
.  for _dir_ in ${_GCC_LIBDIRS:N*not_found*}
_GCC_LDFLAGS+=	-L${_dir_} ${COMPILER_RPATH_FLAG}${_dir_}
.  endfor
.endif

LDFLAGS+=	${_GCC_LDFLAGS}

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
.if !empty(TOOLS_USE_CROSS_COMPILE:M[yY][eE][sS])
_GCC_BIN_PREFIX=	${MACHINE_GNU_PLATFORM}-
.endif
_GCC_BIN_PREFIX?=	# empty
GCC_VERSION_SUFFIX?=	# empty
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}gcc${GCC_VERSION_SUFFIX})
_GCC_VARS+=	CC
_GCC_CC=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gcc${GCC_VERSION_SUFFIX}
_ALIASES.CC=	cc gcc
CCPATH=		${_GCCBINDIR}/${_GCC_BIN_PREFIX}gcc${GCC_VERSION_SUFFIX}
PKG_CC:=	${_GCC_CC}
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}cpp${GCC_VERSION_SUFFIX})
_GCC_VARS+=	CPP
_GCC_CPP=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}cpp${GCC_VERSION_SUFFIX}
_ALIASES.CPP=	cpp
CPPPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}cpp${GCC_VERSION_SUFFIX}
PKG_CPP:=	${_GCC_CPP}
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}g++${GCC_VERSION_SUFFIX})
_GCC_VARS+=	CXX
_GCC_CXX=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}g++${GCC_VERSION_SUFFIX}
_ALIASES.CXX=	c++ g++
CXXPATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}g++${GCC_VERSION_SUFFIX}
PKG_CXX:=	${_GCC_CXX}
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}g77${GCC_VERSION_SUFFIX})
_GCC_VARS+=	FC
_GCC_FC=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}g77${GCC_VERSION_SUFFIX}
_ALIASES.FC=	f77 g77
FC=		g77
FCPATH=		${_GCCBINDIR}/${_GCC_BIN_PREFIX}g77${GCC_VERSION_SUFFIX}
F77PATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}g77${GCC_VERSION_SUFFIX}
PKG_FC:=	${_GCC_FC}
PKGSRC_FORTRAN?=	g77
.endif
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}gfortran${GCC_VERSION_SUFFIX})
_GCC_VARS+=	FC
_GCC_FC=	${_GCC_DIR}/bin/${_GCC_BIN_PREFIX}gfortran${GCC_VERSION_SUFFIX}
_ALIASES.FC=	gfortran
FC=		gfortran
FCPATH=		${_GCCBINDIR}/${_GCC_BIN_PREFIX}gfortran${GCC_VERSION_SUFFIX}
F77PATH=	${_GCCBINDIR}/${_GCC_BIN_PREFIX}gfortran${GCC_VERSION_SUFFIX}
PKG_FC:=	${_GCC_FC}
PKGSRC_FORTRAN?=	gfortran
.endif
#GNAT doesn't provide 'ada' but always provides 'gnatls' - inspired by gprbuild
.if exists(${_GCCBINDIR}/${_GCC_BIN_PREFIX}gnatls)
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
#PKG_ADA:=	${_GCC_ADA}
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
# This is really useful var for gnatmake
GNATMAKE=	${_GCC_GMK}
.endif
_COMPILER_STRIP_VARS+=	${_GCC_VARS}

# Pass the required flags to imake to tell it we're using gcc on Solaris.
.if ${OPSYS} == "SunOS"
IMAKEOPTS+=	-DHasGcc2=YES -DHasGcc2ForCplusplus=YES
.endif

.if ${OPSYS} == "AIX"
# On AIX the GCC toolchain recognizes -maix32 and -maix64,
# -m32 or -m64 are not recognized.
_COMPILER_ABI_FLAG.32=	-maix32
_COMPILER_ABI_FLAG.64=	-maix64
# On HP-UX the GCC toolchain must be specifically targeted to an ABI,
# -m32 or -m64 are not recognized.
.elif ${OPSYS} == "HPUX"
_COMPILER_ABI_FLAG.32=	# empty
_COMPILER_ABI_FLAG.64=	# empty
.elif !empty(MACHINE_ARCH:Mmips*)
_COMPILER_ABI_FLAG.32=	-mabi=n32	# ABI == "32" == "n32"
_COMPILER_ABI_FLAG.n32=	-mabi=n32
_COMPILER_ABI_FLAG.o32=	-mabi=32
_COMPILER_ABI_FLAG.64=	-mabi=64
.elif !empty(MACHINE_ARCH:Maarch64*)
_COMPILER_ABI_FLAG.32=	-m32
_COMPILER_ABI_FLAG.64=	# empty
.else
_COMPILER_ABI_FLAG.32=	-m32
_COMPILER_ABI_FLAG.64=	-m64
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
.  if ${PKGPATH} != devel/libtool-base && ${PKGPATH} != devel/binutils && \
      empty(PKGPATH:Mlang/gcc4?) && empty(PKGPATH:Mlang/gcc[5-9]) && \
      empty(PKGPATH:Mlang/gcc10) && empty(PKGPATH:Mlang/gcc12) && \
      empty(PKGPATH:Mlang/gcc13)
.    if !empty(_GCC_PKGBASE:Mgcc6)
.      include "../../lang/gcc6-libs/buildlink3.mk"
.    elif !empty(_GCC_PKGBASE:Mgcc7)
.      include "../../lang/gcc7-libs/buildlink3.mk"
.    elif !empty(_GCC_PKGBASE:Mgcc8)
.      include "../../lang/gcc8-libs/buildlink3.mk"
.    elif !empty(_GCC_PKGBASE:Mgcc9)
.      include "../../lang/gcc9-libs/buildlink3.mk"
.    elif !empty(_GCC_PKGBASE:Mgcc10)
.      include "../../lang/gcc10-libs/buildlink3.mk"
.    elif !empty(_GCC_PKGBASE:Mgcc12)
.      include "../../lang/gcc12-libs/buildlink3.mk"
.    elif !empty(_GCC_PKGBASE:Mgcc13)
.      include "../../lang/gcc13-libs/buildlink3.mk"
.    else
PKG_FAIL_REASON+=	"No USE_PKGSRC_GCC_RUNTIME support for ${CC_VERSION}"
.    endif
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

# On systems without a Fortran compiler, pull one in if needed.
PKGSRC_FORTRAN?=gfortran

_GCC_NEEDS_A_FORTRAN=	no
.if empty(_USE_PKGSRC_GCC:M[yY][eE][sS]) && !(defined(FCPATH) && exists(${FCPATH}))
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

.if ${OPSYS} == "Interix" && !empty(_GCCBINDIR:M/opt/gcc.*)
COMPILER_INCLUDE_DIRS=	${_GCCBINDIR:H}/include ${_OPSYS_INCLUDE_DIRS}
COMPILER_LIB_DIRS=	${_GCCBINDIR:H}/lib ${_OPSYS_LIB_DIRS}
.endif

#.READONLY: GCC_REQD
_GCC_REQD_EFFECTIVE:=	${GCC_REQD}

.endif	# COMPILER_GCC_MK
