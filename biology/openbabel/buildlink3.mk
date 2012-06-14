# $NetBSD: buildlink3.mk,v 1.2 2012/06/14 07:43:21 sbd Exp $

BUILDLINK_TREE+=	openbabel

.if !defined(OPENBABEL_BUILDLINK3_MK)
OPENBABEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openbabel+=	openbabel>=2.3.0
BUILDLINK_ABI_DEPENDS.openbabel?=	openbabel>=2.3.0nb4
BUILDLINK_PKGSRCDIR.openbabel?=	../../biology/openbabel

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# OPENBABEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openbabel
