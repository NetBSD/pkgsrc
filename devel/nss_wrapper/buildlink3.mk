# $NetBSD: buildlink3.mk,v 1.1 2025/09/06 18:27:52 riastradh Exp $

BUILDLINK_TREE+=	nss_wrapper

.if !defined(NSS_WRAPPER_BUILDLINK3_MK)

BUILDLINK_API_DEPENDS.nss_wrapper+=	nss_wrapper>=1.1.16
BUILDLINK_ABI_DEPENDS.nss_wrapper+=	nss_wrapper>=1.1.16
BUILDLINK_PKGSRCDIR.nss_wrapper=	../../devel/nss_wrapper

.endif

BUILDLINK_TREE+=	-nss_wrapper
