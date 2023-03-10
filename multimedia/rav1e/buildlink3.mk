# $NetBSD: buildlink3.mk,v 1.1 2023/03/10 21:36:29 ryoon Exp $

BUILDLINK_TREE+=	rav1e

.if !defined(RAV1E_BUILDLINK3_MK)
RAV1E_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rav1e+=	rav1e>=0.6.3
BUILDLINK_PKGSRCDIR.rav1e?=	../../multimedia/rav1e

.endif	# RAV1E_BUILDLINK3_MK

BUILDLINK_TREE+=	-rav1e
