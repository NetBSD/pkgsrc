# $NetBSD: options.mk,v 1.3 2012/02/01 21:57:38 is Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ns-flash
PKG_SUPPORTED_OPTIONS=	nspluginwrapper

# XXXX: If nspluginwrapper is enabled and this package is installed after
# firefox (or similar) it will install a system wide wrapped plugin into
# @PREFIX/lib/<browser>/plugins. If it is installed before a browser
# it will install a plugin for the current user in ~/.mozilla/plugins/
# or similar. This is inconsistant and potentially confusing.

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "Linux"
PKG_SUGGESTED_OPTIONS=  nspluginwrapper
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnspluginwrapper)
DEPENDS+= nspluginwrapper>0:../../www/nspluginwrapper
.if ${OPSYS} == "NetBSD" && (!empty(OS_VERSION:M5.[0-9].*) || \
			!empty(OS_VERSION:M[0-4].*))
DEPENDS+= libflashsupport<1.1:../../multimedia/libflashsupport10
.else
DEPENDS+= libflashsupport{,-pulse}>0:../../multimedia/libflashsupport
.endif
INSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.nspluginwrapper
DEINSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.nspluginwrapper
.endif
