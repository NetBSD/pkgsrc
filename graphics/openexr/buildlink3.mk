# $NetBSD: buildlink3.mk,v 1.13 2014/04/10 06:21:18 obache Exp $

BUILDLINK_TREE+=	openexr

.if !defined(OPENEXR_BUILDLINK3_MK)
OPENEXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openexr+=	openexr>=1.6.1
BUILDLINK_ABI_DEPENDS.openexr+=	openexr>=2.1.0nb1
BUILDLINK_PKGSRCDIR.openexr?=	../../graphics/openexr

PTHREAD_OPTS+=	require

.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # OPENEXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-openexr
