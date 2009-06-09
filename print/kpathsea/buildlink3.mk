# $NetBSD: buildlink3.mk,v 1.3 2009/06/09 21:29:17 minskim Exp $

BUILDLINK_TREE+=	kpathsea

.if !defined(KPATHSEA_BUILDLINK3_MK)
KPATHSEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpathsea+=	kpathsea>=5.0.0
BUILDLINK_PKGSRCDIR.kpathsea?=	../../print/kpathsea
BUILDLINK_FILES.kpathsea+=	bin/kpsewhich
.endif # KPATHSEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpathsea
