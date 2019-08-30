# $NetBSD: buildlink3.mk,v 1.15 2019/08/30 13:30:58 nia Exp $

BUILDLINK_TREE+=	smpeg

.if !defined(SMPEG_BUILDLINK3_MK)
SMPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.smpeg+=	smpeg>=0.4.4nb3
BUILDLINK_ABI_DEPENDS.smpeg+=	smpeg>=0.4.4nb16
BUILDLINK_PKGSRCDIR.smpeg?=	../../multimedia/smpeg

.include "../../devel/SDL/buildlink3.mk"
.endif # SMPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-smpeg
