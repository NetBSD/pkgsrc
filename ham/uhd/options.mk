# $NetBSD: options.mk,v 1.1 2014/09/08 07:12:05 mef Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.uhd
PKG_SUPPORTED_OPTIONS=	doxygen manual
PKG_SUGGESTED_OPTIONS=	doxygen manual

.include	"../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
.endif

.if !empty(PKG_OPTIONS:Mmanual)
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
PLIST_SRC+=		${PKGDIR}/PLIST.manual
.endif
