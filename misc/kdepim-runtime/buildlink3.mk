# $NetBSD: buildlink3.mk,v 1.3 2023/11/08 13:20:08 wiz Exp $

BUILDLINK_TREE+=	kdepim-runtime

.if !defined(KDEPIM_RUNTIME_BUILDLINK3_MK)
KDEPIM_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepim-runtime+=	kdepim-runtime>=20.04.1
BUILDLINK_ABI_DEPENDS.kdepim-runtime?=	kdepim-runtime>=23.04.3nb2
BUILDLINK_PKGSRCDIR.kdepim-runtime?=	../../misc/kdepim-runtime

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../misc/akonadi-notes/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDEPIM_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepim-runtime
