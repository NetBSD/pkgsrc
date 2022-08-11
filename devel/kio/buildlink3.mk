# $NetBSD: buildlink3.mk,v 1.39 2022/08/11 05:08:10 gutteridge Exp $

BUILDLINK_TREE+=	kio

.if !defined(KIO_BUILDLINK3_MK)
KIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kio+=	kio>=5.21.0
BUILDLINK_ABI_DEPENDS.kio?=	kio>=5.93.0nb2
BUILDLINK_PKGSRCDIR.kio?=	../../devel/kio

BUILDLINK_FILES.kio+=		share/dbus-1/interfaces/kf5_org.kde.*.xml

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kbookmarks/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/kjobwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# KIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-kio
