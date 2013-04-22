# $NetBSD: buildlink3.mk,v 1.2 2013/04/22 06:03:36 rodent Exp $

BUILDLINK_TREE+=	ccrtp

.if !defined(CCRTP_BUILDLINK3_MK)
CCRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccrtp+=	ccrtp>=2.0.0
BUILDLINK_PKGSRCDIR.ccrtp?=	../../net/ccrtp

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/ucommon/buildlink3.mk"
.endif # CCRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccrtp
