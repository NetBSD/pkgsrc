# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/28 08:45:14 cheusov Exp $

BUILDLINK_TREE+=	heirloom-libcommon

.if !defined(HEIRLOOM_LIBCOMMON_BUILDLINK3_MK)
HEIRLOOM_LIBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.heirloom-libcommon+=	heirloom-libcommon>=070227
BUILDLINK_PKGSRCDIR.heirloom-libcommon?=	../../devel/heirloom-libcommon
BUILDLINK_DEPMETHOD.heirloom-libcommon?=	build
BUILDLINK_INCDIRS.heirloom-libcommon+=		include/heirloom
.endif # HEIRLOOM_LIBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-heirloom-libcommon
