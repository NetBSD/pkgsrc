# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:17 joerg Exp $

BUILDLINK_TREE+=	libdaemon

.if !defined(LIBDAEMON_BUILDLINK3_MK)
LIBDAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdaemon+=	libdaemon>=0.10
BUILDLINK_PKGSRCDIR.libdaemon?=		../../devel/libdaemon
.endif # LIBDAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdaemon
