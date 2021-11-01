# $NetBSD: buildlink3.mk,v 1.1 2021/11/01 14:15:42 ryoon Exp $

BUILDLINK_TREE+=	sfsexp

.if !defined(SFSEXP_BUILDLINK3_MK)
SFSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sfsexp+=	sfsexp>=1.3.1pre20210719
BUILDLINK_PKGSRCDIR.sfsexp?=	../../devel/sfsexp
.endif	# SFSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-sfsexp
