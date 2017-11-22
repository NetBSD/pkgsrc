# $NetBSD: buildlink3.mk,v 1.1 2017/11/22 19:30:48 minskim Exp $

BUILDLINK_TREE+=	flatbuffers

.if !defined(FLATBUFFERS_BUILDLINK3_MK)
FLATBUFFERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flatbuffers+=	flatbuffers>=1.8.0
BUILDLINK_PKGSRCDIR.flatbuffers?=	../../devel/flatbuffers
.endif	# FLATBUFFERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flatbuffers
