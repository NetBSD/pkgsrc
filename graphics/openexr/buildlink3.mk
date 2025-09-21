# $NetBSD: buildlink3.mk,v 1.28 2025/09/21 15:11:35 wiz Exp $

BUILDLINK_TREE+=	openexr

.if !defined(OPENEXR_BUILDLINK3_MK)
OPENEXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openexr+=	openexr>=3.0.5
BUILDLINK_ABI_DEPENDS.openexr+=	openexr>=3.4.0
BUILDLINK_PKGSRCDIR.openexr?=	../../graphics/openexr

PTHREAD_OPTS+=	require

USE_CXX_FEATURES+=	c++17 filesystem

.include "../../devel/libdeflate/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENEXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-openexr
