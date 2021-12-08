# $NetBSD: buildlink3.mk,v 1.2 2021/12/08 16:01:43 adam Exp $

BUILDLINK_TREE+=	gsound

.if !defined(GSOUND_BUILDLINK3_MK)
GSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsound+=	gsound>=1.0.2
BUILDLINK_ABI_DEPENDS.gsound?=	gsound>=1.0.2nb3
BUILDLINK_PKGSRCDIR.gsound?=	../../audio/gsound

.include "../../devel/glib2/buildlink3.mk"
.endif	# GSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsound
