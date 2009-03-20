# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:21 joerg Exp $

BUILDLINK_TREE+=	libnet11

.if !defined(LIBNET11_BUILDLINK3_MK)
LIBNET11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet11+=	libnet11>=1.1.2.1
BUILDLINK_PKGSRCDIR.libnet11?=		../../devel/libnet11

BUILDLINK_INCDIRS.libnet11+=		include/libnet11
BUILDLINK_LIBDIRS.libnet11+=		lib/libnet11
BUILDLINK_CPPFLAGS.libnet11+=		-lnet
.endif # LIBNET11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnet11
