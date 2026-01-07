# $NetBSD: buildlink3.mk,v 1.29 2026/01/07 08:46:00 wiz Exp $

BUILDLINK_TREE+=	libgadu

.if !defined(LIBGADU_BUILDLINK3_MK)
LIBGADU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgadu+=	libgadu>=1.12.2
BUILDLINK_ABI_DEPENDS.libgadu?=	libgadu>=1.12.2nb40
BUILDLINK_PKGSRCDIR.libgadu?=	../../chat/libgadu

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif	# LIBGADU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgadu
