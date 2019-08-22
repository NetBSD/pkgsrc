# $NetBSD: buildlink3.mk,v 1.35 2019/08/22 12:23:29 ryoon Exp $

BUILDLINK_TREE+=	analitza

.if !defined(ANALITZA_BUILDLINK3_MK)
ANALITZA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.analitza+=	analitza>=4.8.0
BUILDLINK_ABI_DEPENDS.analitza?=	analitza>=4.14.3nb17
BUILDLINK_PKGSRCDIR.analitza?=		../../math/analitza

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# ANALITZA_BUILDLINK3_MK

BUILDLINK_TREE+=	-analitza
