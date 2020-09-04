# $NetBSD: buildlink3.mk,v 1.1 2020/09/04 10:13:16 nia Exp $

BUILDLINK_TREE+=	libmesode

.if !defined(LIBMESODE_BUILDLINK3_MK)
LIBMESODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmesode+=	libmesode>=0.9.1
BUILDLINK_PKGSRCDIR.libmesode?=		../../chat/libmesode

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBMESODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmesode
