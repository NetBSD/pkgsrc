# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:15 joerg Exp $

BUILDLINK_TREE+=	hdf

.if !defined(HDF_BUILDLINK3_MK)
HDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf+=	hdf>=4.1r5
BUILDLINK_ABI_DEPENDS.hdf?=	hdf>=4.2r1nb1
BUILDLINK_PKGSRCDIR.hdf?=	../../devel/hdf
.endif # HDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hdf
