# $NetBSD: buildlink3.mk,v 1.3 2026/02/06 10:04:42 wiz Exp $

BUILDLINK_TREE+=	alkimia

.if !defined(ALKIMIA_BUILDLINK3_MK)
ALKIMIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alkimia+=	alkimia>=8.2.1
BUILDLINK_ABI_DEPENDS.alkimia?=	alkimia>=8.2.1nb2
BUILDLINK_PKGSRCDIR.alkimia?=	../../finance/alkimia

.include "../../devel/gmp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# ALKIMIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-alkimia
