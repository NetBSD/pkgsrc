# $NetBSD: buildlink3.mk,v 1.39 2020/03/10 22:08:54 wiz Exp $

BUILDLINK_TREE+=	analitza

.if !defined(ANALITZA_BUILDLINK3_MK)
ANALITZA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.analitza+=	analitza>=19.08.3
BUILDLINK_ABI_DEPENDS.analitza?=	analitza>=19.12.1nb2
BUILDLINK_PKGSRCDIR.analitza?=	../../math/analitza

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# ANALITZA_BUILDLINK3_MK

BUILDLINK_TREE+=	-analitza
