# $NetBSD: buildlink3.mk,v 1.47 2020/03/08 16:48:03 wiz Exp $

BUILDLINK_TREE+=	libgdata

.if !defined(LIBGDATA_BUILDLINK3_MK)
LIBGDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgdata+=	libgdata>=0.6.4
BUILDLINK_ABI_DEPENDS.libgdata+=	libgdata>=0.16.1nb27
BUILDLINK_PKGSRCDIR.libgdata?=		../../net/libgdata


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/liboauth/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"

.endif	# LIBGDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgdata
