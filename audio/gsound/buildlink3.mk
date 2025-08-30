# $NetBSD: buildlink3.mk,v 1.8 2025/08/30 22:44:37 wiz Exp $

BUILDLINK_TREE+=	gsound

.if !defined(GSOUND_BUILDLINK3_MK)
GSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsound+=	gsound>=1.0.2
BUILDLINK_ABI_DEPENDS.gsound+=	gsound>=1.0.3nb6
BUILDLINK_PKGSRCDIR.gsound?=	../../audio/gsound

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# GSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsound
