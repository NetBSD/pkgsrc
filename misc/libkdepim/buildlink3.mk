# $NetBSD: buildlink3.mk,v 1.14 2025/10/23 20:38:26 wiz Exp $

BUILDLINK_TREE+=	libkdepim

.if !defined(LIBKDEPIM_BUILDLINK3_MK)
LIBKDEPIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdepim+=	libkdepim>=17.12.1
BUILDLINK_ABI_DEPENDS.libkdepim?=		libkdepim>=23.08.4nb11
BUILDLINK_PKGSRCDIR.libkdepim?=		../../misc/libkdepim

BUILDLINK_FILES.libkdepim+=	share/dbus-1/interfaces/org.kde.*.xml

.include "../../databases/kldap/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../misc/akonadi-search/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDEPIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdepim
