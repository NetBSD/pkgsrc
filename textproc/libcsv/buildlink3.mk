# $NetBSD: buildlink3.mk,v 1.1 2016/07/20 23:00:13 cheusov Exp $

BUILDLINK_TREE+=	libcsv

.if !defined(LIBCSV_BUILDLINK3_MK)
LIBCSV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcsv+=	libcsv>=3.0.3
BUILDLINK_PKGSRCDIR.libcsv?=	../../textproc/libcsv
.endif	# LIBCSV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcsv
