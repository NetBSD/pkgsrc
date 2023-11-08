# $NetBSD: buildlink3.mk,v 1.19 2023/11/08 13:20:45 wiz Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.95.3nb1
BUILDLINK_ABI_DEPENDS.clamav+=	clamav>=0.103.10nb2
BUILDLINK_PKGSRCDIR.clamav?=	../../security/clamav

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# CLAMAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-clamav
