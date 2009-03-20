# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:05 joerg Exp $

BUILDLINK_TREE+=	mpeg

.if !defined(MPEG_BUILDLINK3_MK)
MPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpeg+=	mpeg>=1.3.1
BUILDLINK_ABI_DEPENDS.mpeg+=	mpeg>=1.3.1nb1
BUILDLINK_PKGSRCDIR.mpeg?=	../../multimedia/mpeg-lib
.endif # MPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpeg
