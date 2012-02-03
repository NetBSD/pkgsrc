# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/03 14:43:12 drochner Exp $

BUILDLINK_TREE+=	p11-kit

.if !defined(P11_KIT_BUILDLINK3_MK)
P11_KIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.10
BUILDLINK_PKGSRCDIR.p11-kit?=	../../security/p11-kit
.endif	# P11_KIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p11-kit
