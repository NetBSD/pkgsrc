# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:10 wiz Exp $

BUILDLINK_TREE+=	kdepim-runtime

.if !defined(KDEPIM_RUNTIME_BUILDLINK3_MK)
KDEPIM_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdepim-runtime+=	kdepim-runtime>=20.04.1
BUILDLINK_ABI_DEPENDS.kdepim-runtime?=	kdepim-runtime>=25.08.3nb2
BUILDLINK_PKGSRCDIR.kdepim-runtime?=	../../misc/kdepim-runtime

.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/libkgapi/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/kf6-kdav/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../textproc/libkolabxml/buildlink3.mk"
.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDEPIM_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdepim-runtime
