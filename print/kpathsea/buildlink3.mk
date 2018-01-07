# $NetBSD: buildlink3.mk,v 1.5 2018/01/07 13:04:28 rillig Exp $

BUILDLINK_TREE+=	kpathsea

.if !defined(KPATHSEA_BUILDLINK3_MK)
KPATHSEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpathsea+=	kpathsea>=6.0.0
BUILDLINK_PKGSRCDIR.kpathsea?=		../../print/kpathsea
BUILDLINK_FILES.kpathsea+=		bin/kpsewhich
.endif # KPATHSEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpathsea
