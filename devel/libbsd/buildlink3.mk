# $NetBSD: buildlink3.mk,v 1.2 2022/12/19 16:05:43 vins Exp $

BUILDLINK_TREE+=	libbsd

.if !defined(LIBBSD_BUILDLINK3_MK)
LIBBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbsd+=	libbsd>=0.11.7
BUILDLINK_PKGSRCDIR.libbsd?=	../../devel/libbsd

BUILDLINK_CFLAGS.libbsd+=	-I${BUILDLINK_PREFIX.libbsd}/include/bsd -DLIBBSD_OVERLAY
BUILDLINK_LDFLAGS.libbsd+=	-lbsd -lmd

.include "../../devel/libmd/buildlink3.mk"
.endif	# LIBBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbsd
