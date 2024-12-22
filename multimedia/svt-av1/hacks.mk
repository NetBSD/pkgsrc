# $NetBSD: hacks.mk,v 1.1 2024/12/22 16:44:30 nia Exp $

.if !defined(SVT_AV1_HACKS_MK)
SVT_AV1_HACKS_MK=		# defined

### [Mon Sun Dec 22 17:37:18 CET 2024 : nia]
### GCC 9 and earlier lack certain ARM NEON intrinsics such as vld1_s16_x2
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		neon-intrin
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NEON=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NEON_DOTPROD=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NEON_I8MM=OFF
.endif

.endif
