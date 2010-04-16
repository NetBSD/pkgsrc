# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/16 15:42:10 reed Exp $

BUILDLINK_TREE+=	opencore-amr

.if !defined(OPENCORE_AMR_BUILDLINK3_MK)
OPENCORE_AMR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencore-amr+=	opencore-amr>=0.1.2
BUILDLINK_PKGSRCDIR.opencore-amr?=	../../audio/opencore-amr
.endif	# OPENCORE_AMR_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencore-amr
