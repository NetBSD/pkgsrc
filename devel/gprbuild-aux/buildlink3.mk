# $NetBSD: buildlink3.mk,v 1.4 2016/11/26 18:34:47 marino Exp $

BUILDLINK_TREE+=	gprbuild-aux

.if !defined(GPRBUILD_AUX_BUILDLINK3_MK)
GPRBUILD_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild-aux+=	gprbuild-aux>=20130416
BUILDLINK_PKGSRCDIR.gprbuild-aux?=	../../devel/gprbuild-aux
BUILDLINK_DEPMETHOD.gprbuild-aux?=	build

.include "../../textproc/xmlada/buildlink3.mk"
.endif	# GPRBUILD_AUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gprbuild-aux
