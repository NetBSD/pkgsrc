# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/15 12:57:49 obache Exp $

BUILDLINK_TREE+=	libbind

.if !defined(LIBBIND_BUILDLINK3_MK)
LIBBIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbind+=	libbind>=6.0
BUILDLINK_PKGSRCDIR.libbind?=	../../net/libbind
.endif	# LIBBIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbind
