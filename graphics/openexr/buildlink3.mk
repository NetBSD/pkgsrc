# $NetBSD: buildlink3.mk,v 1.17 2021/07/08 21:13:06 markd Exp $

BUILDLINK_TREE+=	openexr

.if !defined(OPENEXR_BUILDLINK3_MK)
OPENEXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openexr+=	openexr>=3.0.5
BUILDLINK_ABI_DEPENDS.openexr+=	openexr>=3.0.5
BUILDLINK_PKGSRCDIR.openexr?=	../../graphics/openexr

PTHREAD_OPTS+=	require

# C++14
GCC_REQD+=	6

.include "../../math/imath/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENEXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-openexr
