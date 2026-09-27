# $NetBSD: buildlink3.mk,v 1.2 2026/09/27 07:37:25 wiz Exp $

BUILDLINK_TREE+=	flatbuffers

.if !defined(FLATBUFFERS_BUILDLINK3_MK)
FLATBUFFERS_BUILDLINK3_MK:=

BUILDLINK_FILES.flatbuffers+=		bin/flatc

BUILDLINK_API_DEPENDS.flatbuffers+=	flatbuffers>=1.8.0
BUILDLINK_PKGSRCDIR.flatbuffers?=	../../devel/flatbuffers
.endif	# FLATBUFFERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flatbuffers
