# $NetBSD: version.mk,v 1.2 2018/09/06 07:50:20 nia Exp $
#
# used by emulators/libretro-core-info/Makefile
# used by emulators/libretro-database/Makefile
# used by emulators/libretro-glsl-shaders/Makefile
# used by emulators/retroarch-assets/Makefile

.if !defined(RETROARCH_VERSION)
RETROARCH_VERSION=	1.7.4
.endif
