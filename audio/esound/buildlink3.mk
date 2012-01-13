# $NetBSD: buildlink3.mk,v 1.12 2012/01/13 10:54:45 obache Exp $

BUILDLINK_TREE+=	esound

.if !defined(ESOUND_BUILDLINK3_MK)
ESOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.esound+=	esound>=0.2.18
BUILDLINK_ABI_DEPENDS.esound+=	esound>=0.2.41nb1
BUILDLINK_PKGSRCDIR.esound?=	../../audio/esound

.include "../../audio/libaudiofile/buildlink3.mk"
.endif # ESOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-esound
