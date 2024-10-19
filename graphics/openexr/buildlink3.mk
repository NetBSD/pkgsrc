# $NetBSD: buildlink3.mk,v 1.25 2024/10/19 11:55:04 wiz Exp $

BUILDLINK_TREE+=	openexr

.if !defined(OPENEXR_BUILDLINK3_MK)
OPENEXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openexr+=	openexr>=3.0.5
BUILDLINK_ABI_DEPENDS.openexr+=	openexr>=3.3.0
BUILDLINK_PKGSRCDIR.openexr?=	../../graphics/openexr

PTHREAD_OPTS+=	require

USE_CXX_FEATURES+=		c++14

.include "../../devel/libdeflate/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENEXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-openexr
