# $NetBSD: buildlink3.mk,v 1.11 2013/01/26 21:36:24 adam Exp $

BUILDLINK_TREE+=	simgear

.if !defined(SIMGEAR_BUILDLINK3_MK)
SIMGEAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simgear+=	simgear>=2.0.0nb6
BUILDLINK_ABI_DEPENDS.simgear+=	simgear>=2.8.0nb4
BUILDLINK_PKGSRCDIR.simgear?=	../../games/simgear
BUILDLINK_DEPMETHOD.simgear?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # SIMGEAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-simgear
