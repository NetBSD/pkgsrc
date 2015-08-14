# $NetBSD: options.mk,v 1.3 2015/08/14 06:19:13 mef Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.uhd
PKG_SUPPORTED_OPTIONS=	doxygen manual
PKG_SUGGESTED_OPTIONS=	doxygen manual

.include	"../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
DEPENDS+=		doxygen>=1.8.9.1:../../devel/doxygen
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
.endif

.if !empty(PKG_OPTIONS:Mmanual)
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
#PLIST_SRC+=		${PKGDIR}/PLIST.manual
.endif
