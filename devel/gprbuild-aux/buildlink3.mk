# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/03 19:04:02 drochner Exp $

BUILDLINK_TREE+=	gprbuild-aux

.if !defined(GPRBUILD_AUX_BUILDLINK3_MK)
GPRBUILD_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gprbuild-aux+=	gprbuild-aux>=20101120
BUILDLINK_PKGSRCDIR.gprbuild-aux?=	../../devel/gprbuild-aux

.include "../../textproc/xmlada/buildlink3.mk"
.endif	# GPRBUILD_AUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gprbuild-aux
