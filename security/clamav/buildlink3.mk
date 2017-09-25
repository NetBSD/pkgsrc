# $NetBSD: buildlink3.mk,v 1.7 2017/09/25 22:27:43 joerg Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.95.3nb1
BUILDLINK_ABI_DEPENDS.clamav+=	clamav>=0.98.7nb2
BUILDLINK_PKGSRCDIR.clamav?=	../../security/clamav
.endif	# CLAMAV_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_TREE+=	-clamav
