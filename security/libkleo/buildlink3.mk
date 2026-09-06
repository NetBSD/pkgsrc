# $NetBSD: buildlink3.mk,v 1.23 2026/09/06 11:03:06 markd Exp $

BUILDLINK_TREE+=	libkleo

.if !defined(LIBKLEO_BUILDLINK3_MK)
LIBKLEO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkleo+=	libkleo>=25.08.3
BUILDLINK_ABI_DEPENDS.libkleo?=	libkleo>=25.08.3nb9
BUILDLINK_PKGSRCDIR.libkleo?=	../../security/libkleo

BUILDLINK_FILES.libkleo+=	share/KPim6Libkleo/find-modules/*
BUILDLINK_FILES.libkleo+=	share/KPim6Libkleo/modules/*
 
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKLEO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkleo
