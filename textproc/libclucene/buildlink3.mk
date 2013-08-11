# $NetBSD: buildlink3.mk,v 1.3 2013/08/11 16:06:25 jaapb Exp $

BUILDLINK_TREE+=	libclucene

.if !defined(LIBCLUCENE_BUILDLINK3_MK)
LIBCLUCENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclucene+=	libclucene>=2.2.0
BUILDLINK_PKGSRCDIR.libclucene?=	../../textproc/libclucene
.endif # LIBCLUCENE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclucene
