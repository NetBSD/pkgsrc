# $NetBSD: buildlink3.mk,v 1.20 2009/03/25 09:21:20 adam Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.94.2
BUILDLINK_PKGSRCDIR.clamav?=	../../mail/clamav

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # CLAMAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-clamav
