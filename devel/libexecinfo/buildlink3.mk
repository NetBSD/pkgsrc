# $NetBSD: buildlink3.mk,v 1.1.1.1 2013/03/14 22:27:15 asau Exp $

BUILDLINK_TREE+=	libexecinfo

.if !defined(LIBEXECINFO_BUILDLINK3_MK)
LIBEXECINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexecinfo+=	libexecinfo>=1.1
BUILDLINK_ABI_DEPENDS.libexecinfo+=	libexecinfo>=1.1
BUILDLINK_PKGSRCDIR.libexecinfo?=	../../devel/libexecinfo
.endif	# LIBEXECINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexecinfo
