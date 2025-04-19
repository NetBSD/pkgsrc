# $NetBSD: buildlink3.mk,v 1.69 2025/04/19 07:58:11 wiz Exp $

BUILDLINK_TREE+=	libgdata

.if !defined(LIBGDATA_BUILDLINK3_MK)
LIBGDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgdata+=	libgdata>=0.6.4
BUILDLINK_ABI_DEPENDS.libgdata+=	libgdata>=0.18.1nb8
BUILDLINK_PKGSRCDIR.libgdata?=		../../net/libgdata


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif	# LIBGDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgdata
