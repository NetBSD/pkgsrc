# $NetBSD: buildlink3.mk,v 1.13 2023/10/24 22:10:43 wiz Exp $

BUILDLINK_TREE+=	podofo

.if !defined(PODOFO_BUILDLINK3_MK)
PODOFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.podofo+=	podofo>=0.9.5nb1
BUILDLINK_ABI_DEPENDS.podofo?=	podofo>=0.9.8nb3
BUILDLINK_PKGSRCDIR.podofo?=	../../print/podofo

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# PODOFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-podofo
