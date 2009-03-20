# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	esound

.if !defined(ESOUND_BUILDLINK3_MK)
ESOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.esound+=	esound>=0.2.18
BUILDLINK_ABI_DEPENDS.esound+=	esound>=0.2.35nb1
BUILDLINK_PKGSRCDIR.esound?=	../../audio/esound

.include "../../audio/libaudiofile/buildlink3.mk"
.endif # ESOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-esound
