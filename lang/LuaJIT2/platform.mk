# $NetBSD: platform.mk,v 1.2 2024/08/17 15:20:21 bsiegert Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(PLATFORM_SUPPORTS_LUAJIT)

.  for _luajit_arch in aarch64* *arm* i386 mips* powerpc x86_64
LUAJIT_PLATFORMS+=		*-*-${_luajit_arch}
.  endfor

.  for _luajit_platform in ${LUAJIT_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_luajit_platform})
PLATFORM_SUPPORTS_LUAJIT=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_LUAJIT?=	no

.endif # !defined(PLATFORM_SUPPORTS_LUAJIT)
