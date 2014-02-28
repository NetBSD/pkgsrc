# $NetBSD: buildlink3.mk,v 1.1 2014/02/28 14:49:17 mspo Exp $

BUILDLINK_TREE+=	ck

.if !defined(CK_BUILDLINK3_MK)
CK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ck+=	ck>=0.4.1
BUILDLINK_PKGSRCDIR.ck?=	../../devel/concurrencykit
.endif	# CK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ck
