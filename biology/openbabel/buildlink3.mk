# $NetBSD: buildlink3.mk,v 1.7 2020/08/17 20:17:17 leot Exp $

BUILDLINK_TREE+=	openbabel

.if !defined(OPENBABEL_BUILDLINK3_MK)
OPENBABEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openbabel+=	openbabel>=3.0.0nb1
BUILDLINK_ABI_DEPENDS.openbabel?=	openbabel>=3.1.1nb1
BUILDLINK_PKGSRCDIR.openbabel?=		../../biology/openbabel

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# OPENBABEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openbabel
