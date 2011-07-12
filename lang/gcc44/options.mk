# $NetBSD: options.mk,v 1.4 2011/07/12 18:05:58 hans Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc44
PKG_SUPPORTED_OPTIONS=	nls c++ fortran java objc #ada
PKG_SUGGESTED_OPTIONS=	c++ fortran java objc
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

PKG_OPTIONS_LEGACY_VARS+=	BUILD_CXX:c++
PKG_OPTIONS_LEGACY_VARS+=	BUILD_FORTRAN:fortran
PKG_OPTIONS_LEGACY_VARS+=	BUILD_JAVA:java
PKG_OPTIONS_LEGACY_VARS+=	BUILD_OBJC:objc

.include "../../mk/bsd.options.mk"

###
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
USE_TOOLS+=		msgfmt
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
### Optional languages
### Ada could be added although there is a bootstrapping issue.  See
### ../gcc34-ada for guidance
###

LANGS=		c

.if !empty(PKG_OPTIONS:Mjava)
.  if empty(PKG_OPTIONS:Mc++)
PKG_OPTIONS+=	c++
.  endif
LANGS+=		java
REPLACE_PYTHON=	libjava/contrib/aot-compile.in
.endif

.if !empty(PKG_OPTIONS:Mc++)
LANGS+=		c++
.endif

.if !empty(PKG_OPTIONS:Mfortran)
LANGS+=		fortran
.endif

.if !empty(PKG_OPTIONS:Mobjc)
LANGS+=		objc
.endif

#.if !empty(PKG_OPTIONS:Mada)
#LANGS+=	ada
#.endif
