# $NetBSD: buildlink3.mk,v 1.1.1.1 2014/10/29 23:10:29 cheusov Exp $

BUILDLINK_TREE+=	liblbfgs

.if !defined(LIBLBFGS_BUILDLINK3_MK)
LIBLBFGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblbfgs+=	liblbfgs>=1.10
BUILDLINK_PKGSRCDIR.liblbfgs?=	../../math/liblbfgs
.endif # LIBLBFGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblbfgs
