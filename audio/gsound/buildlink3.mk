# $NetBSD: buildlink3.mk,v 1.7 2025/04/24 14:13:13 wiz Exp $

BUILDLINK_TREE+=	gsound

.if !defined(GSOUND_BUILDLINK3_MK)
GSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsound+=	gsound>=1.0.2
BUILDLINK_ABI_DEPENDS.gsound+=	gsound>=1.0.3nb4
BUILDLINK_PKGSRCDIR.gsound?=	../../audio/gsound

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# GSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsound
