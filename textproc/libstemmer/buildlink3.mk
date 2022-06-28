# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:36:12 wiz Exp $

BUILDLINK_TREE+=	libstemmer

.if !defined(LIBSTEMMER_BUILDLINK3_MK)
LIBSTEMMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstemmer+=	libstemmer>=2.0.0
BUILDLINK_ABI_DEPENDS.libstemmer?=	libstemmer>=2.1.0nb2
BUILDLINK_PKGSRCDIR.libstemmer?=	../../textproc/libstemmer
.endif	# LIBSTEMMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstemmer
