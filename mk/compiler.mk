# $NetBSD: compiler.mk,v 1.107 2023/08/02 15:59:58 nia Exp $
#
# This Makefile fragment implements handling for supported C/C++/Fortran
# compilers.
#
# The following variables may be set by the pkgsrc user in mk.conf:
#
# PKGSRC_COMPILER
#	A list of values specifying the chain of compilers to be used by
#	pkgsrc to build packages.
#
#	Valid values are:
#		ccc		Compaq C Compilers (Tru64)
#		ccache		compiler cache (chainable)
#		clang		Clang C and Objective-C compiler
#		distcc		distributed C/C++ (chainable)
#		f2c		Fortran 77 to C compiler (chainable)
#		icc		Intel C++ Compiler (Linux)
#		ido		SGI IRIS Development Option cc (IRIX 5)
#		gcc		GNU
#		hp		HP-UX C/aC++ compilers
#		mipspro		Silicon Graphics, Inc. MIPSpro (n32/n64)
#		mipspro-ucode	Silicon Graphics, Inc. MIPSpro (o32)
#		pcc		Portable C Compiler
#		sunpro		Sun Microsystems, Inc. WorkShip/Forte/Sun
#				ONE Studio
#		xlc		IBM's XL C/C++ compiler suite (Darwin/MacOSX)
#
#	The default is "gcc".  You can use ccache and/or distcc with
#	an appropriate PKGSRC_COMPILER setting, e.g. "ccache distcc
#	gcc".  You can also use "f2c" to overlay the lang/f2c package
#	over the C compiler instead of using the system Fortran
#	compiler.  The chain should always end in a real compiler.
#	This should only be set in /etc/mk.conf.
#
# COMPILER_USE_SYMLINKS
#	If set to yes, use symlinks for the compiler drivers, otherwise
#	shell scripts are created.  The default is yes.
#
# CHECK_COMPILER
#	If set to yes, fail early if the compiler.mk variables are not
#	set correctly.
#
# ALLOW_NEWER_COMPILER
#	If set to no, fail early if a package requires newer compiler
#	features than supported by the system's compiler. If set to
#	yes (the default), pkgsrc may attempt to build a newer compiler
#	to use instead.
#
# The following variables may be set by a package:
#
# USE_LANGUAGES
#	Declares the languages that should be made available via
#	pkgsrc's compiler wrappers.
#
#	If the package assumes the compiler defaults to a specific
#	language version, the USE_LANGUAGES variable can also be used
#	to force the inclusion of flags such as -std=c++11. In this case,
#	USE_CC_FEATURES/USE_CXX_FEATURES should also be set.
#
#	Valid values are: c, c99, gnu99, c11, gnu11, c17, gnu17, c++, c++03,
#	gnu++03, c++0x, gnu++0x, c++11, gnu++11, c++14, gnu++14, c++17,
#	gnu++17, c++20, gnu++20, fortran, fortran77, java, objc, obj-c++, ada.
#
#	The default is "c".
#
# USE_CC_FEATURES
#
# 	Declares the C compiler features required by the package.
#
#	This is used to (optionally) install a newer compiler
#	than provided by the system, or to skip building the package.
#
#	Valid values are: c11, c99, has_include.
#
# USE_CXX_FEATURES
#
# 	Declares the C++ compiler features required by the package.
#
#	This is used to (optionally) install a newer compiler
#	than provided by the system, to or skip building the package.
#
#	Valid values are: c++11, c++14, c++17, c++20, has_include,
#	regex, filesystem, unique_ptr, charconv, parallelism_ts,
#	put_time, is_trivially_copy_constructible.
#
# FORCE_C_STD
#
#	Overrides the compiler's default C dialect to ensure that a
#	specific language variant is used.  This is useful if a package
#	uses features from a later or earlier C standard but doesn't set
#	-std=cXX, since the default dialect choice of different compiler
#	versions is not consistent.  It is also useful if a package
#	wants to use GNU language extensions without setting -std=gnuXX.
#
#	Valid values are: c90, c99, c11, gnu90, gnu99, gnu11
#
# FORCE_CXX_STD
#
#	Overrides the compiler's default C++ dialect to ensure that a
#	specific language variant is used.  This is useful if a package
#	uses features from a later or earlier C++ standard but doesn't set
#	-std=c++XX, since the default dialect choice of different compiler
#	versions is not consistent.  It is also useful if a package
#	wants to use GNU language extensions without setting -std=gnu++XX.
#
#	Valid values are: c++03, c++11, c++14, c++17, c++20, gnu++03,
#	gnu++11, gnu++17, gnu++20
#
# The following variables are defined, and available for testing in
# package Makefiles:
#
# CC_VERSION
#	The compiler and version being used, e.g.,
#
#	.include "../../mk/compiler.mk"
#
#	.if !empty(CC_VERSION:Mgcc-3*)
#	...
#	.endif
#
# Keywords: compiler

.if !defined(BSD_COMPILER_MK)
BSD_COMPILER_MK=	defined

_VARGROUPS+=		compiler
_USER_VARS.compiler=	PKGSRC_COMPILER USE_PKGSRC_GCC ABI COMPILER_USE_SYMLINKS
_PKG_VARS.compiler=	USE_LANGUAGES GCC_REQD NOT_FOR_COMPILER ONLY_FOR_COMPILER
_SYS_VARS.compiler=	CC_VERSION

.include "bsd.fast.prefs.mk"

# Since most packages need a C compiler, this is the default value.
USE_LANGUAGES?=	c

_C_STD_VERSIONS=	c99 gnu99 c11 gnu11 c17 gnu17
.for _version_ in ${_C_STD_VERSIONS}
.  if !empty(USE_LANGUAGES:M${_version_})
USE_LANGUAGES+=		c
.  endif
.endfor

_CXX_STD_VERSIONS=	gnu++20 c++20 gnu++17 c++17 gnu++14 c++14 gnu++11 c++11 gnu++0x c++0x gnu++03 c++03
.for _version_ in ${_CXX_STD_VERSIONS}
.  if !empty(USE_LANGUAGES:M${_version_})
USE_LANGUAGES+=		c++
.  endif
.endfor

#.READONLY: USE_LANGUAGES
_USE_LANGUAGES_EFFECTIVE:=	${USE_LANGUAGES}

COMPILER_USE_SYMLINKS?=	yes

_COMPILERS=		ccc clang gcc hp icc ido \
			mipspro mipspro-ucode pcc sunpro xlc
_PSEUDO_COMPILERS=	ccache distcc f2c g95

.if defined(NOT_FOR_COMPILER) && !empty(NOT_FOR_COMPILER)
.  for _compiler_ in ${_COMPILERS}
.    if ${NOT_FOR_COMPILER:M${_compiler_}} == ""
_ACCEPTABLE_COMPILERS+=	${_compiler_}
.    endif
.  endfor
.elif defined(ONLY_FOR_COMPILER) && !empty(ONLY_FOR_COMPILER)
.  for _compiler_ in ${_COMPILERS}
.    if ${ONLY_FOR_COMPILER:M${_compiler_}} != ""
_ACCEPTABLE_COMPILERS+=	${_compiler_}
.    endif
.  endfor
.else
_ACCEPTABLE_COMPILERS+=	${_COMPILERS}
.endif

# Currently only gcc-based compilers support Ada
# Override PKGSRC_COMPILER if Ada language specified
.if !empty(USE_LANGUAGES:Mada)
PKGSRC_COMPILER=	gcc
.endif

.if defined(_ACCEPTABLE_COMPILERS)
.  for _acceptable_ in ${_ACCEPTABLE_COMPILERS}
.    for _compiler_ in ${PKGSRC_COMPILER}
.      if !empty(_ACCEPTABLE_COMPILERS:M${_compiler_}) && !defined(_COMPILER)
_COMPILER=	${_compiler_}
.      endif
.    endfor
.  endfor
.endif

.if !defined(_COMPILER)
PKG_FAIL_REASON+=	"No acceptable compiler found for ${PKGNAME}."
.endif

.for _compiler_ in ${PKGSRC_COMPILER}
.  if !empty(_PSEUDO_COMPILERS:M${_compiler_})
_PKGSRC_COMPILER:=	${_compiler_} ${_PKGSRC_COMPILER}
.  endif
.endfor
_PKGSRC_COMPILER:=	${_COMPILER} ${_PKGSRC_COMPILER}

_COMPILER_STRIP_VARS=	# empty

.for _compiler_ in ${_PKGSRC_COMPILER}
.  include "compiler/${_compiler_}.mk"
.endfor
.undef _compiler_

.if !defined(PKG_CPP)
PKG_CPP:=${CPP}
.endif

# Ensure the Solaris linker is used by default.
.if ${OPSYS} == "SunOS"
.  if exists(/usr/ccs/bin/ld)
PKG_LD?=       /usr/ccs/bin/ld
.  elif exists(/usr/bin/ld)
PKG_LD?=       /usr/bin/ld
.  endif
.endif

# Strip the leading paths from the toolchain variables since we manipulate
# the PATH to use the correct executable.
#
.for _var_ in ${_COMPILER_STRIP_VARS}
.  if empty(${_var_}:C/^/_asdf_/1:N_asdf_*)
${_var_}:=	${${_var_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//:T}
.  else
${_var_}:=	${${_var_}:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//:T} ${${_var_}:C/^/_asdf_/1:N_asdf_*}
.  endif
.endfor

# Pass the compiler flag based on the most recent version of the C or C++
# standard required.  We currently assume that each standard is a superset of
# all that come after it.
#
_C_VERSION_REQD=
.for _version_ in ${_C_STD_VERSIONS}
.  if empty(_C_VERSION_REQD) && !empty(USE_LANGUAGES:M${_version_})
_C_VERSION_REQD=	${_version_}
_WRAP_EXTRA_ARGS.CC+=	${_C_STD_FLAG.${_C_VERSION_REQD}}
CWRAPPERS_PREPEND.cc+=	${_C_STD_FLAG.${_C_VERSION_REQD}}
.  endif
.endfor

_CXX_VERSION_REQD=
.for _version_ in ${_CXX_STD_VERSIONS}
.  if empty(_CXX_VERSION_REQD) && !empty(USE_LANGUAGES:M${_version_})
_CXX_VERSION_REQD=	${_version_}
_WRAP_EXTRA_ARGS.CXX+=	${_CXX_STD_FLAG.${_CXX_VERSION_REQD}}
CWRAPPERS_PREPEND.cxx+=	${_CXX_STD_FLAG.${_CXX_VERSION_REQD}}
.  endif
.endfor

.if defined(ABI) && !empty(ABI)
_WRAP_EXTRA_ARGS.CC+=	${_COMPILER_ABI_FLAG.${ABI}}
_WRAP_EXTRA_ARGS.CXX+=	${_COMPILER_ABI_FLAG.${ABI}}
_WRAP_EXTRA_ARGS.FC+=	${_COMPILER_ABI_FLAG.${ABI}}
CWRAPPERS_PREPEND.cc+=	${_COMPILER_ABI_FLAG.${ABI}}
CWRAPPERS_PREPEND.cxx+=	${_COMPILER_ABI_FLAG.${ABI}}
CWRAPPERS_PREPEND.f77+=	${_COMPILER_ABI_FLAG.${ABI}}
.endif

# Enable SSP if the user has chosen to and the compiler supports it.
#
.if ${_PKGSRC_USE_SSP} == "yes" && defined(_SSP_CFLAGS)
_WRAP_EXTRA_ARGS.CC+=	${_SSP_CFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_SSP_CFLAGS}
CWRAPPERS_PREPEND.cc+=	${_SSP_CFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_SSP_CFLAGS}
CWRAPPERS_PREPEND.f77+=	${_SSP_CFLAGS}
.endif

# Enable FORTIFY_SOURCE if the user has chosen to and the compiler
# supports it.
#
.if ${_PKGSRC_USE_FORTIFY} != "no" && defined(_FORTIFY_CFLAGS)
_WRAP_EXTRA_ARGS.CC+=	${_FORTIFY_CFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_FORTIFY_CFLAGS}
CWRAPPERS_PREPEND.cc+=	${_FORTIFY_CFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_FORTIFY_CFLAGS}
.endif

# Enable reproducible executables if the user has chosen to and the
# compiler supports it.
#
.if ${_PKGSRC_MKREPRO} != "no" && defined(_MKREPRO_CFLAGS)
_WRAP_EXTRA_ARGS.CC+=	${_MKREPRO_CFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_MKREPRO_CFLAGS}
CWRAPPERS_PREPEND.cc+=	${_MKREPRO_CFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_MKREPRO_CFLAGS}
.endif

# Enable relocation read-only if the user has chosen to and the compiler
# supports it.
#
.if (${_PKGSRC_USE_RELRO} == "partial" || ${_PKGSRC_USE_RELRO} == "full") \
     && defined(_RELRO_LDFLAGS)
LDFLAGS+=		${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+= ${_RELRO_LDFLAGS}
.endif

# Enable position-independent executables if the user has chosen to and
# the compiler supports it.
#
.if ${_PKGSRC_MKPIE} == "yes" && ${PKGSRC_OVERRIDE_MKPIE:tl} == "no"
_WRAP_EXTRA_ARGS.CC+=	${_MKPIE_CFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_MKPIE_CFLAGS}
CWRAPPERS_PREPEND.cc+=	${_MKPIE_CFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_MKPIE_CFLAGS}
CWRAPPERS_PREPEND.f77+=	${_MKPIE_FCFLAGS}
.endif

# Add debug flags if the user has requested CTF and the compiler supports it.
#
.if ${_PKGSRC_USE_CTF} == "yes" && defined(_CTF_CFLAGS)
_WRAP_EXTRA_ARGS.CC+=	${_CTF_CFLAGS}
CWRAPPERS_APPEND.cc+=	${_CTF_CFLAGS}
.endif

# Add sysroot if using cross-compilation tools.
#
.if !empty(TOOLS_USE_CROSS_COMPILE:M[yY][eE][sS])
CWRAPPERS_PREPEND.cc+=	--sysroot=${TOOLS_CROSS_DESTDIR:Q}
CWRAPPERS_PREPEND.cxx+=	--sysroot=${TOOLS_CROSS_DESTDIR:Q}
CWRAPPERS_PREPEND.ld+=	--sysroot=${TOOLS_CROSS_DESTDIR:Q}
# XXX cross fortran
.endif

# If the languages are not requested, force them not to be available
# in the generated wrappers.
#
_FAIL_WRAPPER.CC=	${WRKDIR}/.compiler/bin/c-fail-wrapper
_FAIL_WRAPPER.CXX=	${WRKDIR}/.compiler/bin/c++-fail-wrapper
_FAIL_WRAPPER.FC=	${WRKDIR}/.compiler/bin/fortran-fail-wrapper
_FAIL_WRAPPER.ADA=	${WRKDIR}/.compiler/bin/ada-fail-wrapper

${_FAIL_WRAPPER.CC}: fail-wrapper
${_FAIL_WRAPPER.CXX}: fail-wrapper
${_FAIL_WRAPPER.FC}: fail-wrapper
${_FAIL_WRAPPER.ADA}: fail-wrapper

.PHONY: fail-wrapper
fail-wrapper: .USE
	${RUN}								\
	${TEST} -d ${.TARGET:H} || ${MKDIR} ${.TARGET:H};		\
	exec 1>${.TARGET};						\
	${ECHO} '#!'${TOOLS_SHELL:Q};					\
	${ECHO} 'wrapperlog="$${TOOLS_WRAPPER_LOG-'${_TOOLS_WRAP_LOG:Q}'}"'; \
	${ECHO} 'lang="${.TARGET:T:S/-fail-wrapper//}"'; \
	${ECHO} 'msg="*** Please consider adding $$lang to USE_LANGUAGES in the package Makefile."'; \
	${ECHO} '${ECHO} "$$msg" >> $$wrapperlog'; \
	${ECHO} '${ECHO} "$$msg" > ${WARNING_DIR}/${.TARGET:T}'; \
	${ECHO} '${ECHO} "PKGSRC-WARNING: Something is trying to run the $$lang compiler," 1>&2'; \
	${ECHO} '${ECHO} "PKGSRC-WARNING: but it is not added to USE_LANGUAGES in the package Makefile." 1>&2'; \
	${ECHO} 'exit 1';						\
	${CHMOD} +x ${.TARGET}

.if empty(USE_LANGUAGES:Mc) && empty(USE_LANGUAGES:Mobjc) && empty(USE_LANGUAGES:Mobjc-c++)
PKG_CC:=		${_FAIL_WRAPPER.CC}
ALL_ENV+=		CPP=${CPP:Q}
override-tools: ${_FAIL_WRAPPER.CC}
.endif
.if empty(USE_LANGUAGES:Mc++)
PKG_CXX:=		${_FAIL_WRAPPER.CXX}
ALL_ENV+=		CXXCPP=${CPP:Q} # to make some Autoconf scripts happy
override-tools: ${_FAIL_WRAPPER.CXX}
.endif
.if empty(USE_LANGUAGES:Mfortran) && empty(USE_LANGUAGES:Mfortran77)
PKG_FC:=		${_FAIL_WRAPPER.FC}
override-tools: ${_FAIL_WRAPPER.FC}
.endif
.if empty(USE_LANGUAGES:Mada)
PKG_ADA:=		${_FAIL_WRAPPER.ADA}
override-tools: ${_FAIL_WRAPPER.ADA}
.endif

.if !empty(DRAGONFLY_CCVER) && ${OPSYS} == "DragonFly"
ALL_ENV+=		CCVER=${DRAGONFLY_CCVER}
.endif

.endif	# BSD_COMPILER_MK

.if ${CHECK_COMPILER:Uno:tl} == yes
.  if ${USE_LANGUAGES:O:u} != ${_USE_LANGUAGES_EFFECTIVE:O:u}
.warning For ${PKGPATH}, only languages "${_USE_LANGUAGES_EFFECTIVE}" are used, the others in "${USE_LANGUAGES}" were defined too late.
.  endif
.  if ${GCC_REQD:U:O:u} != ${_GCC_REQD_EFFECTIVE:U:O:u}
.warning For ${PKGPATH}, only GCC_REQD "${_GCC_REQD_EFFECTIVE}" are used, the others in "${GCC_REQD}" were defined too late.
.  endif
.endif
