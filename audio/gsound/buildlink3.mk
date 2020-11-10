# $NetBSD: buildlink3.mk,v 1.1 2020/11/10 16:36:15 nia Exp $

BUILDLINK_TREE+=	gsound

.if !defined(GSOUND_BUILDLINK3_MK)
GSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsound+=	gsound>=1.0.2
BUILDLINK_PKGSRCDIR.gsound?=	../../audio/gsound

.include "../../devel/glib2/buildlink3.mk"
.endif	# GSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsound
