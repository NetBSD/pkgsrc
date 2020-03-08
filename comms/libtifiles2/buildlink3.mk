# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:28 wiz Exp $

BUILDLINK_TREE+=	libtifiles2

.if !defined(LIBTIFILES2_BUILDLINK3_MK)
LIBTIFILES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtifiles2+=	libtifiles2>=1.1.5
BUILDLINK_ABI_DEPENDS.libtifiles2?=	libtifiles2>=1.1.5nb1
BUILDLINK_PKGSRCDIR.libtifiles2?=	../../comms/libtifiles2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../comms/libticonv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTIFILES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtifiles2
