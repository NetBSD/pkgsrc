# $NetBSD: buildlink3.mk,v 1.1 2019/04/29 15:51:23 bacon Exp $

BUILDLINK_TREE+=	libaec

.if !defined(LIBAEC_BUILDLINK3_MK)
LIBAEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaec+=	libaec>=1.0.4
BUILDLINK_PKGSRCDIR.libaec?=	../../archivers/libaec
.endif	# LIBAEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaec
