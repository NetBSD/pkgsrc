# $NetBSD: bsd.compiler.mk,v 1.4 2004/02/01 11:14:04 jlam Exp $
#
# This Makefile fragment implements handling for supported C/C++/Fortran
# compilers.
#
# The following variables are used:
#
# PKGSRC_COMPILER
#	A list of values specifying the chain of compilers to be used by
#	pkgsrc to build packages.
#
#	Valid values are:
#		distcc		distributed C/C++ (chainable)
#		ccache		compiler cache (chainable)
#		gcc		GNU
#		mipspro		Silicon Graphics, Inc. MIPSpro
#		sunpro		Sun Microsystems, Inc. WorkShip/Forte/Sun
#				ONE Studio
#
#	The default is "gcc".  You can use ccache and/or distcc with an
#	appropriate PKGSRC_COMPILER setting, e.g. "ccache distcc gcc".
#	The chain should always end in a real compiler.
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
#	GCC_REQD instead of the native compiler.
#
# USE_GCC_SHLIB
#	Indicates that a package uses GCC shared libraries, so we
#	register a runtime dependency on the compiler package.
#
# The following variables are defined, and available for testing in
# package Makefiles:
#
# CC_VERSION
#	The compiler and version being used, e.g.,
#
#	.include "../../mk/bsd.prefs.mk"
#
#	.if !empty(CC_VERSION:Mgcc-3*)
#	...
#	.endif
#
# The following variables are deprecated:
#
# USE_GCC2, USE_GCC3, USE_SUNPRO, USE_MIPSPRO

.if !defined(BSD_COMPILER_MK)
BSD_COMPILER_MK=	defined

# Support some deprecated variables for a while.  They'll be removed
# after the pkgsrc-2004Q1 branch is cut.
#
.if defined(USE_GCC2)
GCC_REQD?=		2.8.0
PKGSRC_COMPILER?=	gcc
.elif defined(USE_GCC3)
GCC_REQD?=		3.0
PKGSRC_COMPILER?=	gcc
.elif defined(USE_PKGSRC_GCC)
_USE_PKGSRC_GCC=	yes
PKGSRC_COMPILER?=	gcc
.elif defined(USE_SUNPRO)
PKGSRC_COMPILER?=	sunpro
.elif defined(USE_MIPSPRO)
PKGSRC_COMPILER?=	mipspro
.else
PKGSRC_COMPILER?=	gcc
.endif

_PKGSRC_COMPILER=	# empty
.for _compiler_ in ${PKGSRC_COMPILER}
.  if empty(_PKGSRC_COMPILER:M${_compiler_})
_PKGSRC_COMPILER:=	${_compiler_} ${_PKGSRC_COMPILER}
.  endif
.endfor

.for _compiler_ in ${_PKGSRC_COMPILER}
.  include "../../mk/compiler/${_compiler_}.mk"
.endfor

.endif	# BSD_COMPILER_MK
