# $NetBSD: buildlink3.mk,v 1.4 2009/12/15 21:30:51 joerg Exp $

BUILDLINK_TREE+=	akode

.if !defined(AKODE_BUILDLINK3_MK)
AKODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akode+=	akode>=2.0.2
BUILDLINK_ABI_DEPENDS.akode+=	akode>=2.0.2nb2
BUILDLINK_PKGSRCDIR.akode?=	../../audio/akode

.include "../../devel/libltdl/buildlink3.mk"
.endif # AKODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-akode
