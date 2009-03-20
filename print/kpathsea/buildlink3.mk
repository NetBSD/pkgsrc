# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:14 joerg Exp $

BUILDLINK_TREE+=	kpathsea

.if !defined(KPATHSEA_BUILDLINK3_MK)
KPATHSEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpathsea+=	kpathsea>=3.5.7
BUILDLINK_PKGSRCDIR.kpathsea?=	../../print/kpathsea
BUILDLINK_FILES.kpathsea+=	bin/kpsewhich
.endif # KPATHSEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpathsea
