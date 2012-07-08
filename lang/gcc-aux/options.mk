# $NetBSD: options.mk,v 1.1 2012/07/08 19:30:38 marino Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc-aux
PKG_SUPPORTED_OPTIONS=  ada cxx fortran objc testsuite nls static
PKG_SUGGESTED_OPTIONS=  ada cxx fortran objc

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+= static
.endif

.include "../../mk/bsd.options.mk"


#########################
##  ADD LANGUAGE: Ada  ##
#########################

.if !empty(PKG_OPTIONS:Mada)
LANGS+= ada
APPLY_DIFFS+= ada
.endif


#########################
##  ADD LANGUAGE: C++  ##
#########################

.if !empty(PKG_OPTIONS:Mcxx)
LANGS+= c++
APPLY_DIFFS+= cxx
.endif


#############################
##  ADD LANGUAGE: Fortran  ##
#############################

.if empty(PKG_OPTIONS:Mfortran)
EXTRA_CONFARGS+= --disable-libquadmath
.else
LANGS+= fortran
APPLY_DIFFS+= fortran
.if ${OPSYS} == "NetBSD"
EXTRA_CONFARGS+= --disable-libquadmath
.else
EXTRA_CONFARGS+= --enable-libquadmath
.endif
.endif


#################################
##  ADD LANGUAGE: Objective-C  ##
#################################

.if !empty(PKG_OPTIONS:Mobjc)
LANGS+= objc
.endif


#########################
##  TESTSUITE SUPPORT  ##
#########################

.if !empty(PKG_OPTIONS:Mtestsuite)
BUILD_DEPENDS+= dejagnu>=1.4:../../devel/dejagnu
APPLY_DIFFS+= ada-testsuite
APPLY_DIFFS+= cxx-testsuite
APPLY_DIFFS+= gcc-testsuite
APPLY_DIFFS+= fortran-testsuite
.endif


#################################
##  NATIONAL LANGUAGE SUPPORT  ##
#################################

.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+= msgfmt
EXTRA_CONFARGS+= --enable-nls
.include "../../devel/gettext-lib/buildlink3.mk"
.else
EXTRA_CONFARGS+= --disable-nls
.endif


###############################
##  STATICALLY BUILT OPTION  ##
###############################

# NetBSD must be built statically to support dl_iterate_phdr
# error handling.  The base compiler doesn't support despite it although
# NetBSD's realtime linker supports dl_iterate_phdr
# Setting the option by default on NetBSD is cosmetic; regardless of
# setting, NetBSD will always be built statically.
#
# The "static" option is handled in the post-extract phase.
