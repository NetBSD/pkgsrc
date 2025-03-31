# $NetBSD: buildlink3.mk,v 1.4 2025/03/31 15:39:27 nia Exp $

BUILDLINK_TREE+=	openal-soft

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.*)
OPENAL_USE_CXX?=	no
.else
OPENAL_USE_CXX?=	yes
.endif

.if ${OPENAL_USE_CXX:tl} == "no"
# this defines OPENAL_SOFT_BUILDLINK3_MK so the next sections aren't used
.  include "../../audio/openal-soft-c/buildlink3.mk"
.endif

.if !empty(CC_VERSION:Mgcc-[56789].*) || \
    !empty(CC_VERSION:Mgcc-10.*) || !empty(CC_VERSION:Mgcc-11.*)
.  include "../../audio/openal-soft-cxx14/buildlink3.mk"
.endif

.if !defined(OPENAL_SOFT_BUILDLINK3_MK)
OPENAL_SOFT_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++20

BUILDLINK_API_DEPENDS.openal-soft+=	openal-soft>=1.5.304
BUILDLINK_PKGSRCDIR.openal-soft?=	../../audio/openal-soft
.endif	# OPENAL_SOFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal-soft
