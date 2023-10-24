# $NetBSD: buildlink3.mk,v 1.2 2023/10/24 22:08:21 wiz Exp $

BUILDLINK_TREE+=	libmesode

.if !defined(LIBMESODE_BUILDLINK3_MK)
LIBMESODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmesode+=	libmesode>=0.9.1
BUILDLINK_ABI_DEPENDS.libmesode?=		libmesode>=0.10.1nb1
BUILDLINK_PKGSRCDIR.libmesode?=		../../chat/libmesode

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBMESODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmesode
