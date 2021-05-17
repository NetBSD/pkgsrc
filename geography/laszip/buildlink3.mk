# $NetBSD: buildlink3.mk,v 1.1 2021/05/17 10:01:31 thor Exp $

BUILDLINK_TREE+=	laszip

.if !defined(LASZIP_BUILDLINK3_MK)
LASZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.laszip+=	laszip>=3.0.0
BUILDLINK_PKGSRCDIR.laszip?=	../../geography/laszip
.endif	# LASZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-laszip
