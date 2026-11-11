# $NetBSD: buildlink3.mk,v 1.69 2026/11/11 11:54:28 wiz Exp $

BUILDLINK_TREE+=	analitza

.if !defined(ANALITZA_BUILDLINK3_MK)
ANALITZA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.analitza+=	analitza>=25.08.2
BUILDLINK_ABI_DEPENDS.analitza?=	analitza>=26.08.0nb4
BUILDLINK_PKGSRCDIR.analitza?=		../../math/analitza

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# ANALITZA_BUILDLINK3_MK

BUILDLINK_TREE+=	-analitza
