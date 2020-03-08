# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:28 wiz Exp $

BUILDLINK_TREE+=	libticalcs2

.if !defined(LIBTICALCS2_BUILDLINK3_MK)
LIBTICALCS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticalcs2+=	libticalcs2>=1.1.7
BUILDLINK_ABI_DEPENDS.libticalcs2?=	libticalcs2>=1.1.7nb1
BUILDLINK_PKGSRCDIR.libticalcs2?=	../../comms/libticalcs2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/libtifiles2/buildlink3.mk"
.include "../../comms/libticonv/buildlink3.mk"
.include "../../comms/libticables2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBTICALCS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticalcs2
