# $NetBSD: buildlink3.mk,v 1.11 2013/06/03 10:05:31 wiz Exp $

BUILDLINK_TREE+=	analitza

.if !defined(ANALITZA_BUILDLINK3_MK)
ANALITZA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.analitza+=	analitza>=4.8.0
BUILDLINK_ABI_DEPENDS.analitza?=	analitza>=4.10.3nb1
BUILDLINK_PKGSRCDIR.analitza?=	../../math/analitza

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# ANALITZA_BUILDLINK3_MK

BUILDLINK_TREE+=	-analitza
