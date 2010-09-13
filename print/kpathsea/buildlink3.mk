# $NetBSD: buildlink3.mk,v 1.4 2010/09/13 04:06:12 minskim Exp $

BUILDLINK_TREE+=	kpathsea

.if !defined(KPATHSEA_BUILDLINK3_MK)
KPATHSEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpathsea+=	kpathsea>=6.0.0
BUILDLINK_PKGSRCDIR.kpathsea?=	../../print/kpathsea
BUILDLINK_FILES.kpathsea+=	bin/kpsewhich
.endif # KPATHSEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpathsea
