# $NetBSD: hacks.mk,v 1.2 2024/12/22 16:50:10 nia Exp $

.if !defined(SVT_AV1_HACKS_MK)
SVT_AV1_HACKS_MK=		# defined

### [Mon Sun Dec 22 17:37:18 CET 2024 : nia]
### GCC 9 and earlier lack certain ARM NEON intrinsics such as vld1_s16_x2
###
.include "../../mk/compiler.mk"

.if ${MACHINE_ARCH:Maarch64*} && ${CC_VERSION:Mgcc-[0-9]\.*}
PKG_HACKS+=		neon-intrin
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NEON=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NEON_DOTPROD=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NEON_I8MM=OFF
.endif

.endif
