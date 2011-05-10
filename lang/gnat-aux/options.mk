# $NetBSD: options.mk,v 1.1 2011/05/10 13:46:22 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnat-aux
PKG_SUPPORTED_OPTIONS=	ada cxx testada testcxx testgcc
PKG_SUGGESTED_OPTIONS=	ada #cxx

.include "../../mk/bsd.options.mk"


#########################
##  ADD LANGUAGE: Ada  ##
#########################

.if !empty(PKG_OPTIONS:Mada)
LANGS+= ada
.endif


#########################
##  ADD LANGUAGE: C++  ##
#########################

.if !empty(PKG_OPTIONS:Mcxx)
LANGS+= c++
.endif


#########################
##  TESTSUITE SUPPORT  ##
#########################

.if !empty(PKG_OPTIONS:Mtestada) \
 || !empty(PKG_OPTIONS:Mtestcxx) \
 || !empty(PKG_OPTIONS:Mtestgcc)
BUILD_DEPENDS+= dejagnu>=1.4:../../devel/dejagnu
.endif
