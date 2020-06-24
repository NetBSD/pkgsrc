# $NetBSD: platform.mk,v 1.1 2020/06/24 11:16:00 nia Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(PLATFORM_SUPPORTS_LUAJIT)

.  for _luajit_arch in *arm* i386 mipseb mipsel powerpc x86_64
LUAJIT_PLATFORMS+=		*-*-${_luajit_arch}
.  endfor

.  for _luajit_platform in ${LUAJIT_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${_luajit_platform})
PLATFORM_SUPPORTS_LUAJIT=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_LUAJIT?=	no

.endif # !defined(PLATFORM_SUPPORTS_LUAJIT)
