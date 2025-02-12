# $NetBSD: buildlink3.mk,v 1.11 2025/02/12 06:45:33 ryoon Exp $

BUILDLINK_TREE+=	libkleo

.if !defined(LIBKLEO_BUILDLINK3_MK)
LIBKLEO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkleo+=	libkleo>=20.04.1
BUILDLINK_ABI_DEPENDS.libkleo?=	libkleo>=23.08.4nb7
BUILDLINK_PKGSRCDIR.libkleo?=	../../security/libkleo

.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKLEO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkleo
