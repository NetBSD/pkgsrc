# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/11 09:41:35 wiz Exp $

BUILDLINK_TREE+=	podofo

.if !defined(PODOFO_BUILDLINK3_MK)
PODOFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.podofo+=	podofo>=0.7.0
BUILDLINK_PKGSRCDIR.podofo?=	../../nih/podofo
BUILDLINK_DEPMETHOD.podofo?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# PODOFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-podofo
