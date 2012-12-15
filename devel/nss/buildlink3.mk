# $NetBSD: buildlink3.mk,v 1.18 2012/12/15 09:48:00 ryoon Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.14.0
BUILDLINK_ABI_DEPENDS.nss+=	nss>=3.13.1
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
