# $NetBSD: buildlink3.mk,v 1.22 2019/05/05 22:47:27 ryoon Exp $

BUILDLINK_TREE+=	nss

.if !defined(NSS_BUILDLINK3_MK)
NSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nss+=	nss>=3.43nb2
BUILDLINK_ABI_DEPENDS.nss+=	nss>=3.43nb2
BUILDLINK_PKGSRCDIR.nss?=	../../devel/nss

BUILDLINK_LIBDIRS.nss+=		lib/nss
BUILDLINK_RPATHDIRS.nss+=	lib/nss

BUILDLINK_INCDIRS.nss+=		include/nss/nss

.include "../../devel/nspr/buildlink3.mk"
.endif # NSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nss
