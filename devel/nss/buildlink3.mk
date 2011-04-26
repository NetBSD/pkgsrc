# $NetBSD: buildlink3.mk,v 1.13 2011/04/26 14:20:03 tnn Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.12.9.0
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
