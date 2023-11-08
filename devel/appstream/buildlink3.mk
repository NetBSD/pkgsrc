# $NetBSD: buildlink3.mk,v 1.3 2023/11/08 13:18:40 wiz Exp $

BUILDLINK_TREE+=	appstream

.if !defined(APPSTREAM_BUILDLINK3_MK)
APPSTREAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.appstream+=	appstream>=0.16.3
BUILDLINK_ABI_DEPENDS.appstream?=		appstream>=0.16.3nb2
BUILDLINK_PKGSRCDIR.appstream?=		../../devel/appstream

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../textproc/libxmlb/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# APPSTREAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-appstream
