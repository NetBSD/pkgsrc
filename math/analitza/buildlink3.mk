# $NetBSD: buildlink3.mk,v 1.47 2022/11/23 16:18:51 adam Exp $

BUILDLINK_TREE+=	analitza

.if !defined(ANALITZA_BUILDLINK3_MK)
ANALITZA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.analitza+=	analitza>=19.08.3
BUILDLINK_ABI_DEPENDS.analitza?=	analitza>=22.08.1nb1
BUILDLINK_PKGSRCDIR.analitza?=	../../math/analitza

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# ANALITZA_BUILDLINK3_MK

BUILDLINK_TREE+=	-analitza
