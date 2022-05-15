# $NetBSD: buildlink3.mk,v 1.1 2022/05/15 19:12:11 nia Exp $

BUILDLINK_TREE+=	libstrophe

.if !defined(LIBSTROPHE_BUILDLINK3_MK)
LIBSTROPHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstrophe+=	libstrophe>=0.12.0
BUILDLINK_PKGSRCDIR.libstrophe?=	../../chat/libstrophe

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBSTROPHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstrophe
