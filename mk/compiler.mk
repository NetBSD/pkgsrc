# $NetBSD: compiler.mk,v 1.36 2004/10/06 09:49:53 grant Exp $
#
# This Makefile fragment implements handling for supported C/C++/Fortran
# compilers.
#
# The following variables are used by this file:
#
# PKGSRC_COMPILER
#	A list of values specifying the chain of compilers to be used by
#	pkgsrc to build packages.
#
#	Valid values are:
#		distcc		distributed C/C++ (chainable)
#		ccache		compiler cache (chainable)
#		gcc		GNU
#		mipspro		Silicon Graphics, Inc. MIPSpro (n32/n64)
#		mipspro-ucode	Silicon Graphics, Inc. MIPSpro (o32)
#		sunpro		Sun Microsystems, Inc. WorkShip/Forte/Sun
#				ONE Studio
#		xlc		IBM's XL C/C++ compiler suite
#
#	The default is "gcc".  You can use ccache and/or distcc with an
#	appropriate PKGSRC_COMPILER setting, e.g. "ccache distcc gcc".
#	The chain should always end in a real compiler.  This should only
#	be set in /etc/mk.conf.
#
# GCC_REQD
#	A list of version numbers used to determine the minimum
#	version of GCC required by a package.  This value should only
#	be appended to by a package Makefile.
#
#	NOTE: Be conservative when setting GCC_REQD, as lang/gcc3 is
#	known not to build on some platforms, e.g. Darwin.  If gcc3 is
#	required, set GCC_REQD=3.0 so that we do not try to pull in
#	lang/gcc3 unnecessarily and have it fail.
#
# USE_PKGSRC_GCC
#	Force using the appropriate version of GCC from pkgsrc based on
#	GCC_REQD instead of the native compiler.  Should only be set in
#	/etc/mk.conf.
#
# USE_GCC_SHLIB
#	Indicates that a package uses GCC shared libraries, so we
#	register a runtime dependency on the compiler package.
#
# USE_LANGUAGES
#	Lists the languages used in the source code of the package,
#	and is used to determine the correct compilers to install.
#	Valid values are: c, c++, fortran, java, objc.  The default
#	is "c".
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

.if !defined(BSD_COMPILER_MK)
BSD_COMPILER_MK=	defined

.include "../../mk/bsd.prefs.mk"

# XXX Add this gross and completely inaccurate hack.  Packages that
# XXX set USE_GCC_SHLIB should be adjusted to set USE_LANGUAGES
# XXX correctly (most likely by saying it needs either "c++" or
# XXX "c c++").  This is here for now so that ~85 packages won't
# XXX suddenly break.
#
.if defined(USE_GCC_SHLIB)
USE_LANGUAGES?=	c c++
.endif

# By default, assume that the package requires a C compiler.
USE_LANGUAGES?=	c

# Default to using gcc.
PKGSRC_COMPILER?=	gcc

# For environments where there is an external gcc too, but pkgsrc
# should use the pkgsrc one for consistency.
.if defined(USE_PKGSRC_GCC)
_USE_PKGSRC_GCC=	yes
.endif

_COMPILERS=		gcc mipspro mipspro-ucode sunpro xlc
_PSEUDO_COMPILERS=	ccache distcc

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

.for _compiler_ in ${_PKGSRC_COMPILER}
.  include "../../mk/compiler/${_compiler_}.mk"
.endfor

.if defined(ABI) && !empty(ABI)
_WRAP_EXTRA_ARGS.CC+=	${_COMPILER_ABI_FLAG.${ABI}}
_WRAP_EXTRA_ARGS.CXX+=	${_COMPILER_ABI_FLAG.${ABI}}
_WRAP_EXTRA_ARGS.LD+=	${_LINKER_ABI_FLAG.${ABI}}
.endif

.endif	# BSD_COMPILER_MK
