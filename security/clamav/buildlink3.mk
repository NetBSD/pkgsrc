# $NetBSD: buildlink3.mk,v 1.26 2025/10/23 20:39:05 wiz Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=1.4.3
BUILDLINK_ABI_DEPENDS.clamav+=	clamav>=1.4.3nb2
BUILDLINK_PKGSRCDIR.clamav?=	../../security/clamav

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/libmspack/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# CLAMAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-clamav
