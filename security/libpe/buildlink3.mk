# $NetBSD: buildlink3.mk,v 1.1 2021/05/29 23:23:42 khorben Exp $

BUILDLINK_TREE+=	libpe

.if !defined(LIBPE_BUILDLINK3_MK)
LIBPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpe+=	libpe>=0.81
BUILDLINK_ABI_DEPENDS.libpe+=	libpe>=0.81
BUILDLINK_PKGSRCDIR.libpe?=	../../security/libpe

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpe
