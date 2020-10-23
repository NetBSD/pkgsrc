# $NetBSD: buildlink3.mk,v 1.15.4.1 2020/10/23 17:36:23 bsiegert Exp $

BUILDLINK_TREE+=	openexr

.if !defined(OPENEXR_BUILDLINK3_MK)
OPENEXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openexr+=	openexr>=1.6.1
BUILDLINK_ABI_DEPENDS.openexr+=	openexr>=2.5.1
BUILDLINK_PKGSRCDIR.openexr?=	../../graphics/openexr

PTHREAD_OPTS+=	require

# C++14
GCC_REQD+=	6

.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENEXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-openexr
