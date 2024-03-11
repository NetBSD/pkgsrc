# $NetBSD: buildlink3.mk,v 1.24 2024/03/11 14:59:27 ryoon Exp $

BUILDLINK_TREE+=	openexr

.if !defined(OPENEXR_BUILDLINK3_MK)
OPENEXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openexr+=	openexr>=3.0.5
BUILDLINK_ABI_DEPENDS.openexr+=	openexr>=3.2.1
BUILDLINK_PKGSRCDIR.openexr?=	../../graphics/openexr

PTHREAD_OPTS+=	require

USE_CXX_FEATURES+=		c++14

.include "../../devel/libdeflate/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENEXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-openexr
