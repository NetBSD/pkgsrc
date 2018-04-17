# $NetBSD: buildlink3.mk,v 1.2 2018/04/17 13:26:15 wiz Exp $

BUILDLINK_TREE+=	p11-kit

.if !defined(P11_KIT_BUILDLINK3_MK)
P11_KIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.10
BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23
BUILDLINK_PKGSRCDIR.p11-kit?=	../../security/p11-kit
.include "../../devel/libffi/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.endif	# P11_KIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p11-kit
