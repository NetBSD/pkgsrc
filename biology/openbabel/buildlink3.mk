# $NetBSD: buildlink3.mk,v 1.15 2023/04/19 08:08:05 adam Exp $

BUILDLINK_TREE+=	openbabel

.if !defined(OPENBABEL_BUILDLINK3_MK)
OPENBABEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openbabel+=	openbabel>=3.0.0nb1
BUILDLINK_ABI_DEPENDS.openbabel?=	openbabel>=3.1.1nb16
BUILDLINK_PKGSRCDIR.openbabel?=		../../biology/openbabel

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# OPENBABEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openbabel
