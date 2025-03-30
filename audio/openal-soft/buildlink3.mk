# $NetBSD: buildlink3.mk,v 1.3 2025/03/30 09:33:26 nia Exp $

BUILDLINK_TREE+=	openal-soft

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.*)
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
