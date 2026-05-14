# $NetBSD: buildlink3.mk,v 1.6 2026/05/14 17:34:02 ryoon Exp $

BUILDLINK_TREE+=	libaom

.if !defined(LIBAOM_BUILDLINK3_MK)
LIBAOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom+=	libaom>=1.0.0
BUILDLINK_ABI_DEPENDS.libaom+=	libaom>=3.3.0nb1
BUILDLINK_PKGSRCDIR.libaom?=	../../multimedia/libaom
BUILDLINK_FILES.libaom+=	bin/aomdec
BUILDLINK_FILES.libaom+=	bin/aomenc
.endif	# LIBAOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom
