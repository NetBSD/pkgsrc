# $NetBSD: buildlink3.mk,v 1.2 2026/01/07 08:46:56 wiz Exp $

BUILDLINK_TREE+=	alkimia

.if !defined(ALKIMIA_BUILDLINK3_MK)
ALKIMIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alkimia+=	alkimia>=8.2.1
BUILDLINK_ABI_DEPENDS.alkimia?=	alkimia>=8.2.1nb1
BUILDLINK_PKGSRCDIR.alkimia?=	../../finance/alkimia

.include "../../devel/gmp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# ALKIMIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-alkimia
