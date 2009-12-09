# $NetBSD: buildlink3.mk,v 1.3 2009/12/09 12:27:27 obache Exp $

BUILDLINK_TREE+=	libnet10

.if !defined(LIBNET10_BUILDLINK3_MK)
LIBNET10_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet10+=	libnet10>=1.0.2a
BUILDLINK_PKGSRCDIR.libnet10?=		../../devel/libnet10

BUILDLINK_INCDIRS.libnet10+=		include/libnet10
BUILDLINK_LIBDIRS.libnet10+=		lib/libnet10
BUILDLINK_FILES.libnet10+=		bin/libnet10-config
BUILDLINK_FNAME_TRANSFORM.libnet10+=	-e 's|bin/libnet10-config|bin/libnet-config|'
.endif # LIBNET10_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnet10
