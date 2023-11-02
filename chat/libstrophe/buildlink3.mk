# $NetBSD: buildlink3.mk,v 1.3 2023/11/02 13:30:46 nros Exp $

BUILDLINK_TREE+=	libstrophe

.if !defined(LIBSTROPHE_BUILDLINK3_MK)
LIBSTROPHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstrophe+=	libstrophe>=0.12.0
BUILDLINK_ABI_DEPENDS.libstrophe?=	libstrophe>=0.12.3
BUILDLINK_PKGSRCDIR.libstrophe?=	../../chat/libstrophe

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBSTROPHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstrophe
