# $NetBSD: buildlink3.mk,v 1.11 2010/01/16 14:41:25 tnn Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.12.4.5
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
