# $NetBSD: options.mk,v 1.9 2023/04/07 09:15:55 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgcrypt
PKG_SUPPORTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "Darwin"
.  include "../../mk/compiler.mk"
# GCC 3.x (at least 3.3.3 on NetBSD) fails to compile asm() call in
# cipher/rijndael.c:do_padlock()
.  if !${CC_VERSION:Mgcc-3.*}
PKG_SUPPORTED_OPTIONS+=	via-padlock
# With GCC 4.1.3 on NetBSD, do_padlock() crashes with signal 11
.    if ${OPSYS} != "NetBSD"
PKG_SUGGESTED_OPTIONS+=	via-padlock
.    endif
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mvia-padlock)
# Disable VIA Padlock support.
CONFIGURE_ARGS+=	--disable-padlock-support
.endif
