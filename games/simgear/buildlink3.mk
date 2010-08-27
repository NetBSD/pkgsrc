# $NetBSD: buildlink3.mk,v 1.7 2010/08/27 06:11:50 adam Exp $

BUILDLINK_TREE+=	simgear

.if !defined(SIMGEAR_BUILDLINK3_MK)
SIMGEAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simgear+=	simgear>=1.0.0
BUILDLINK_ABI_DEPENDS.simgear+=	simgear>=1.0.0nb2
BUILDLINK_PKGSRCDIR.simgear?=	../../games/simgear
BUILDLINK_DEPMETHOD.simgear?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # SIMGEAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-simgear
