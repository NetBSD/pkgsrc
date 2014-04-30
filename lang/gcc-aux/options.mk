# $NetBSD: options.mk,v 1.2 2014/04/30 16:24:39 marino Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc-aux
PKG_SUPPORTED_OPTIONS=  fortran objc testsuite nls static bootstrap
PKG_SUGGESTED_OPTIONS=  fortran objc nls

.include "../../mk/bsd.options.mk"


# Bootstrap is essentially a maintainer option and it will ignore
# all other options because it is intent on building a bootstrap compiler.


#############################
##  ADD LANGUAGE: Fortran  ##
#############################

.if empty(PKG_OPTIONS:Mfortran) || !empty(PKG_OPTIONS:Mbootstrap)
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

.if !empty(PKG_OPTIONS:Mobjc) && empty(PKG_OPTIONS:Mbootstrap)
LANGS+= objc
.endif


#########################
##  TESTSUITE SUPPORT  ##
#########################

.if !empty(PKG_OPTIONS:Mtestsuite) && empty(PKG_OPTIONS:Mbootstrap)
BUILD_DEPENDS+= dejagnu>=1.4:../../devel/dejagnu
APPLY_DIFFS+= ada-testsuite
APPLY_DIFFS+= cxx-testsuite
APPLY_DIFFS+= gcc-testsuite
APPLY_DIFFS+= fortran-testsuite
.endif


#################################
##  NATIONAL LANGUAGE SUPPORT  ##
#################################

.if !empty(PKG_OPTIONS:Mnls) && empty(PKG_OPTIONS:Mbootstrap)
USE_BUILTIN.iconv= no
USE_TOOLS+= msgfmt
EXTRA_CONFARGS+= --enable-nls
EXTRA_CONFARGS+= --with-libiconv-prefix=${PREFIX}
MY_MAKE_ENV+= ICONVPREFIX=${PREFIX}
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
EXTRA_CONFARGS+= --disable-nls
.endif


###############################
##  STATICALLY BUILT OPTION  ##
###############################

.if !empty(PKG_OPTIONS:Mstatic) && empty(PKG_OPTIONS:Mbootstrap)
EXTRA_CONFARGS+= --with-stage1-ldflags=-static
.endif


#################################
##  BOOTSTRAP COMPILER OPTION  ##
#################################

.if !empty(PKG_OPTIONS:Mbootstrap)
EXTRA_CONFARGS+= --disable-shared --disable-lto
EXTRA_CONFARGS+= --with-stage1-ldflags=-static
EXTRA_CONFARGS+= --with-boot-ldflags=-static
.else
EXTRA_CONFARGS+= --enable-shared
EXTRA_CONFARGS+= --disable-bootstrap
.endif
