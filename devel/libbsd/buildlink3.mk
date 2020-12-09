# $NetBSD: buildlink3.mk,v 1.1 2020/12/09 11:21:46 cheusov Exp $

BUILDLINK_TREE+=	libbsd

.if !defined(LIBBSD_BUILDLINK3_MK)
LIBBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbsd+=	libbsd>=0.10.0
BUILDLINK_PKGSRCDIR.libbsd?=	../../devel/libbsd
.endif	# LIBBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbsd
