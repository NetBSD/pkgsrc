# $NetBSD: options.mk,v 1.8 2019/03/15 00:49:01 mef Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.uhd
PKG_SUPPORTED_OPTIONS=	doxygen manual

.include	"../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
BUILD_DEPENDS+=		doxygen>=1.8.15:../../devel/doxygen
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
CMAKE_ARGS+=     	-DENABLE_DOXYGEN:BOOL=ON
.else
CMAKE_ARGS+=     	-DENABLE_DOXYGEN:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mmanual)
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
PLIST_SRC+=		${PKGDIR}/PLIST.manual
.else
PLIST_SRC+=		${PKGDIR}/PLIST.manual-nogz
.endif
