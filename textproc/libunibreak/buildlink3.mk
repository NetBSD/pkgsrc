# $NetBSD: buildlink3.mk,v 1.1 2024/03/14 19:15:29 markd Exp $

BUILDLINK_TREE+=	libunibreak

.if !defined(LIBUNIBREAK_BUILDLINK3_MK)
LIBUNIBREAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunibreak+=	libunibreak>=6.1
BUILDLINK_PKGSRCDIR.libunibreak?=	../../textproc/libunibreak
.endif	# LIBUNIBREAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunibreak
