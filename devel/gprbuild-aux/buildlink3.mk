# $NetBSD: buildlink3.mk,v 1.2 2012/07/08 20:08:42 marino Exp $

BUILDLINK_TREE+=	gprbuild-aux

.if !defined(GPRBUILD_AUX_BUILDLINK3_MK)
GPRBUILD_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild-aux+=	gprbuild-aux>=20120510
BUILDLINK_PKGSRCDIR.gprbuild-aux?=	../../devel/gprbuild-aux

.include "../../textproc/xmlada/buildlink3.mk"
.endif	# GPRBUILD_AUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gprbuild-aux
