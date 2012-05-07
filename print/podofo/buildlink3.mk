# $NetBSD: buildlink3.mk,v 1.6 2012/05/07 01:53:54 dholland Exp $

BUILDLINK_TREE+=	podofo

.if !defined(PODOFO_BUILDLINK3_MK)
PODOFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.podofo+=	podofo>=0.7.0
BUILDLINK_ABI_DEPENDS.podofo+=	podofo>=0.9.1nb2
BUILDLINK_PKGSRCDIR.podofo?=	../../print/podofo
BUILDLINK_DEPMETHOD.podofo?=	build

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# PODOFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-podofo
