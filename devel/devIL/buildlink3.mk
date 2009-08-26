# $NetBSD: buildlink3.mk,v 1.16 2009/08/26 19:56:43 sno Exp $

BUILDLINK_TREE+=	devIL

.if !defined(DEVIL_BUILDLINK3_MK)
DEVIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.devIL+=	devIL>=1.6.6nb1
BUILDLINK_ABI_DEPENDS.devIL+=	devIL>=1.6.6nb10
BUILDLINK_PKGSRCDIR.devIL?=	../../devel/devIL

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # DEVIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-devIL
