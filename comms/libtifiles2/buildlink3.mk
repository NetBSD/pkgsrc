# $NetBSD: buildlink3.mk,v 1.4 2026/09/02 19:01:13 wiz Exp $

BUILDLINK_TREE+=	libtifiles2

.if !defined(LIBTIFILES2_BUILDLINK3_MK)
LIBTIFILES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtifiles2+=	libtifiles2>=1.1.5
BUILDLINK_ABI_DEPENDS.libtifiles2?=	libtifiles2>=1.1.5nb4
BUILDLINK_PKGSRCDIR.libtifiles2?=	../../comms/libtifiles2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../comms/libticonv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTIFILES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtifiles2
