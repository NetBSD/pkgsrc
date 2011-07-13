# $NetBSD: options.mk,v 1.5 2011/07/13 13:13:43 hans Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc44
PKG_SUPPORTED_OPTIONS=	nls gcc-c++ gcc-fortran gcc-java gcc-objc #gcc-ada
PKG_SUGGESTED_OPTIONS=	gcc-c++ gcc-fortran gcc-java gcc-objc
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

PKG_OPTIONS_LEGACY_VARS+=	BUILD_CXX:gcc-c++
PKG_OPTIONS_LEGACY_VARS+=	BUILD_FORTRAN:gcc-fortran
PKG_OPTIONS_LEGACY_VARS+=	BUILD_JAVA:gcc-java
PKG_OPTIONS_LEGACY_VARS+=	BUILD_OBJC:gcc-objc

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

.if !empty(PKG_OPTIONS:Mgcc-java)
.  if empty(PKG_OPTIONS:Mgcc-c++)
PKG_OPTIONS+=	gcc-c++
.  endif
LANGS+=		java
REPLACE_PYTHON=	libjava/contrib/aot-compile.in
.endif

.if !empty(PKG_OPTIONS:Mgcc-c++)
LANGS+=		c++
.endif

.if !empty(PKG_OPTIONS:Mgcc-fortran)
LANGS+=		fortran
.endif

.if !empty(PKG_OPTIONS:Mgcc-objc)
LANGS+=		objc
.endif

#.if !empty(PKG_OPTIONS:Mgcc-ada)
#LANGS+=	ada
#.endif
