# $NetBSD: options.mk,v 1.11 2023/06/06 12:41:37 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uhd
PKG_SUPPORTED_OPTIONS=	doxygen

.include "../../mk/bsd.options.mk"

PLIST_SRC=	${PLIST_SRC_DFLT}

.if !empty(PKG_OPTIONS:Mdoxygen)
TOOL_DEPENDS+=	doxygen>=1.8.15:../../devel/doxygen
PLIST_SRC+=	${PKGDIR}/PLIST.doxygen
CMAKE_ARGS+=	-DENABLE_MANUAL=ON
CMAKE_ARGS+=	-DENABLE_DOXYGEN=ON
.else
CMAKE_ARGS+=	-DENABLE_MANUAL=OFF
CMAKE_ARGS+=	-DENABLE_DOXYGEN=OFF
.endif
