# $NetBSD: buildlink3.mk,v 1.11 2020/08/17 20:17:19 leot Exp $

BUILDLINK_TREE+=	grantlee

.if !defined(GRANTLEE_BUILDLINK3_MK)
GRANTLEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantlee+=	grantlee>=0.3.0
BUILDLINK_ABI_DEPENDS.grantlee?=	grantlee>=0.5.1nb7
BUILDLINK_PKGSRCDIR.grantlee?=		../../devel/grantlee

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# GRANTLEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantlee
