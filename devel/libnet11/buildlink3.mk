# $NetBSD: buildlink3.mk,v 1.8 2009/12/09 12:27:27 obache Exp $

BUILDLINK_TREE+=	libnet11

.if !defined(LIBNET11_BUILDLINK3_MK)
LIBNET11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet11+=	libnet11>=1.1.2.1
BUILDLINK_PKGSRCDIR.libnet11?=		../../devel/libnet11
BUILDLINK_DEPMETHOD.libnet11?=		build

BUILDLINK_INCDIRS.libnet11+=		include/libnet11
BUILDLINK_LIBDIRS.libnet11+=		lib/libnet11
BUILDLINK_FILES.libnet11+=		bin/libnet11-config
BUILDLINK_FNAME_TRANSFORM.libnet11+=	-e 's|bin/libnet11-config|bin/libnet-config|'
.endif # LIBNET11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnet11
