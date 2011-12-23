# $NetBSD: buildlink3.mk,v 1.9 2011/12/23 13:36:45 drochner Exp $

BUILDLINK_TREE+=	simgear

.if !defined(SIMGEAR_BUILDLINK3_MK)
SIMGEAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simgear+=	simgear>=2.0.0nb6
BUILDLINK_ABI_DEPENDS.simgear+=	simgear>=1.0.0nb2
BUILDLINK_PKGSRCDIR.simgear?=	../../games/simgear
BUILDLINK_DEPMETHOD.simgear?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # SIMGEAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-simgear
