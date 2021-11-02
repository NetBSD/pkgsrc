# $NetBSD: buildlink3.mk,v 1.2 2021/11/02 13:48:03 ryoon Exp $

BUILDLINK_TREE+=	sfsexp

.if !defined(SFSEXP_BUILDLINK3_MK)
SFSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sfsexp+=	sfsexp>=1.3.1pre20211025
BUILDLINK_PKGSRCDIR.sfsexp?=	../../devel/sfsexp
.endif	# SFSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-sfsexp
