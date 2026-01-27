# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:30 wiz Exp $

BUILDLINK_TREE+=	libkleo

.if !defined(LIBKLEO_BUILDLINK3_MK)
LIBKLEO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkleo+=	libkleo>=25.08.3
BUILDLINK_ABI_DEPENDS.libkleo?=	libkleo>=25.08.3nb2
BUILDLINK_PKGSRCDIR.libkleo?=	../../security/libkleo

BUILDLINK_FILES.libkleo+=	share/KPim6Libkleo/find-modules/*

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKLEO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkleo
