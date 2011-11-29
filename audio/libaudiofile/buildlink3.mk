# $NetBSD: buildlink3.mk,v 1.16 2011/11/29 19:39:30 wiz Exp $

BUILDLINK_TREE+=	libaudiofile

.if !defined(LIBAUDIOFILE_BUILDLINK3_MK)
LIBAUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudiofile+=	libaudiofile>=0.2.1
BUILDLINK_ABI_DEPENDS.libaudiofile+=	libaudiofile>=0.2.6nb1
BUILDLINK_PKGSRCDIR.libaudiofile?=	../../audio/libaudiofile
.endif # LIBAUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudiofile
