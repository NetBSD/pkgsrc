# $NetBSD: buildlink3.mk,v 1.1 2020/04/14 14:07:50 ryoon Exp $

BUILDLINK_TREE+=	libstemmer

.if !defined(LIBSTEMMER_BUILDLINK3_MK)
LIBSTEMMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstemmer+=	libstemmer>=2.0.0
BUILDLINK_PKGSRCDIR.libstemmer?=	../../textproc/libstemmer
.endif	# LIBSTEMMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstemmer
