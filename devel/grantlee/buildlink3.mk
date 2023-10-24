# $NetBSD: buildlink3.mk,v 1.14 2023/10/24 22:08:45 wiz Exp $

BUILDLINK_TREE+=	grantlee

.if !defined(GRANTLEE_BUILDLINK3_MK)
GRANTLEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grantlee+=	grantlee>=0.3.0
BUILDLINK_ABI_DEPENDS.grantlee?=	grantlee>=0.5.1nb10
BUILDLINK_PKGSRCDIR.grantlee?=		../../devel/grantlee

BUILDLINK_FILES.grantlee+=		lib/grantlee/0.5/*.so

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# GRANTLEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-grantlee
