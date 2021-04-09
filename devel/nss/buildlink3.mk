# $NetBSD: buildlink3.mk,v 1.24 2021/04/09 06:54:56 wiz Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.43nb2
BUILDLINK_ABI_DEPENDS.nss+=	nss>=3.63nb1
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
