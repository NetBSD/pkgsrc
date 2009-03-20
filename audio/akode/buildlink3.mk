# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	akode

.if !defined(AKODE_BUILDLINK3_MK)
AKODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akode+=	akode>=2.0.2
BUILDLINK_PKGSRCDIR.akode?=	../../audio/akode

.include "../../devel/libltdl/buildlink3.mk"
.endif # AKODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-akode
