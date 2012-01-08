# $NetBSD: options.mk,v 1.2 2012/01/08 11:17:07 marino Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnat-aux
PKG_SUPPORTED_OPTIONS=  ada cxx fortran objc
PKG_SUPPORTED_OPTIONS+= testada testcxx testfortran testobjc testgcc
PKG_SUGGESTED_OPTIONS=  ada cxx fortran objc

.include "../../mk/bsd.options.mk"


#########################
##  ADD LANGUAGE: Ada  ##
#########################

.if !empty(PKG_OPTIONS:Mada)
LANGS+= ada
DISTFILES+= gcc-ada-${GCC_VERSION}.tar.bz2
APPLY_DIFFS+= ada
.endif


#########################
##  ADD LANGUAGE: C++  ##
#########################

.if !empty(PKG_OPTIONS:Mcxx)
LANGS+= c++
DISTFILES+= gcc-g++-${GCC_VERSION}.tar.bz2
APPLY_DIFFS+= cxx
.endif


#############################
##  ADD LANGUAGE: Fortran  ##
#############################

.if empty(PKG_OPTIONS:Mfortran)
QUADOPT= --disable-libquadmath
.else
LANGS+= fortran
DISTFILES+= gcc-fortran-${GCC_VERSION}.tar.bz2
APPLY_DIFFS+= fortran
.if ${OPSYS} == "NetBSD"
QUADOPT= --disable-libquadmath
.else
QUADOPT= --enable-libquadmath
.endif
.endif


#################################
##  ADD LANGUAGE: Objective-C  ##
#################################

.if !empty(PKG_OPTIONS:Mobjc)
LANGS+= objc
DISTFILES+= gcc-objc-${GCC_VERSION}.tar.bz2
.endif


#########################
##  TESTSUITE SUPPORT  ##
#########################

.if !empty(PKG_OPTIONS:Mtestada) \
 || !empty(PKG_OPTIONS:Mtestcxx) \
 || !empty(PKG_OPTIONS:Mtestfortran) \
 || !empty(PKG_OPTIONS:Mtestobjc) \
 || !empty(PKG_OPTIONS:Mtestgcc)
BUILD_DEPENDS+= dejagnu>=1.4:../../devel/dejagnu
DISTFILES+= gcc-testsuite-${GCC_VERSION}.tar.bz2
.if !empty(PKG_OPTIONS:Mtestada)
APPLY_DIFFS+= ada-testsuite
.endif
.if !empty(PKG_OPTIONS:Mtestcxx)
APPLY_DIFFS+= cxx-testsuite
.endif
.if !empty(PKG_OPTIONS:Mtestgcc)
APPLY_DIFFS+= gcc-testsuite
.endif
.if !empty(PKG_OPTIONS:Mtestfortran)
APPLY_DIFFS+= fortran-testsuite
.endif
.endif
