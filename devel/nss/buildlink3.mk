# $NetBSD: buildlink3.mk,v 1.26 2022/06/28 11:31:49 wiz Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.43nb2
BUILDLINK_ABI_DEPENDS.nss+=	nss>=3.80nb1
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
