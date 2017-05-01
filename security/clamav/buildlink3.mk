# $NetBSD: buildlink3.mk,v 1.5.2.1 2017/05/01 08:51:40 bsiegert Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.95.3nb1
BUILDLINK_ABI_DEPENDS.clamav+=	clamav>=0.98.7nb2
BUILDLINK_PKGSRCDIR.clamav?=	../../security/clamav
.endif	# CLAMAV_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_TREE+=	-clamav
