# $NetBSD: options.mk,v 1.1.1.1 2011/11/03 18:14:15 abs Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.adobe-flash-plugin
PKG_SUPPORTED_OPTIONS=	nspluginwrapper pulseaudio

# XXXX: If nspluginwrapper is enabled and this package is installed after
# firefox (or similar) it will install a system wide wrapped plugin into
# @PREFIX/lib/<browser>/plugins. If it is installed before a browser
# it will install a plugin for the current user in ~/.mozilla/plugins/
# or similar. This is inconsistant and potentially confusing.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUGGESTED_OPTIONS=	nspluginwrapper
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnspluginwrapper)
DEPENDS+= nspluginwrapper>0:../../www/nspluginwrapper
.  if !empty(PKG_OPTIONS:Mpulseaudio)
# usr/lib/libpulse.so.0 provided by suse32_gtk2
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pulseaudio
.  else
DEPENDS+= libflashsupport>0:../../multimedia/libflashsupport
.  endif
INSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.nspluginwrapper
DEINSTALL_TEMPLATES+=	${PKGDIR}/INSTALL.nspluginwrapper
.endif
