# $NetBSD: options.mk,v 1.4 2016/01/03 17:13:40 morr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.haproxy
PKG_SUPPORTED_OPTIONS=	pcre ssl deviceatlas
PKG_SUGGESTED_OPTIONS=	pcre ssl

.include "../../mk/bsd.options.mk"

###
### Use libpcre rather than libc for header processing regexp
###
.if !empty(PKG_OPTIONS:Mpcre)
.  include "../../devel/pcre/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_PCRE=1
.endif

###
### Support DeviceAtlas detection.
###
.if !empty(PKG_OPTIONS:Mpcre) && !empty(PKG_OPTIONS:Mdeviceatlas)
DEVICEATLAS_VERSION=	2.1
DEVICEATLAS_DISTFILE=	deviceatlas-enterprise-c-${DEVICEATLAS_VERSION}
DISTFILES=		${DISTNAME}.tar.gz ${DEVICEATLAS_DISTFILE}.zip
DEVICEATLAS_HOMEPAGE=	https://www.deviceatlas.com/deviceatlas-haproxy-module

BUILD_MAKE_FLAGS+=	USE_DEVICEATLAS=1 DEVICEATLAS_SRC=../${DEVICEATLAS_DISTFILE}

.if !exists(${DISTDIR}/${DEVICEATLAS_DISTFILE}.zip)
FETCH_MESSAGE= 		"Please fetch ${DEVICEATLAS_DISTFILE}.zip manually from"
FETCH_MESSAGE+=		"${DEVICEATLAS_HOMEPAGE}"
FETCH_MESSAGE+= 	"and put into"
FETCH_MESSAGE+= 	"${DISTDIR}"
.endif
.endif

###
### Support OpenSSL for termination.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
BUILD_MAKE_FLAGS+=	USE_OPENSSL=1
.endif
