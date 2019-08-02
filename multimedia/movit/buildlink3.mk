# $NetBSD: buildlink3.mk,v 1.1 2019/08/02 10:11:35 nia Exp $

BUILDLINK_TREE+=	movit

.if !defined(MOVIT_BUILDLINK3_MK)
MOVIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.movit+=	movit>=1.6.3
BUILDLINK_PKGSRCDIR.movit?=	../../multimedia/movit

.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.endif	# MOVIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-movit
