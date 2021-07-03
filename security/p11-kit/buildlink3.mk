# $NetBSD: buildlink3.mk,v 1.4 2021/07/03 21:02:45 thor Exp $

BUILDLINK_TREE+=	p11-kit

.if !defined(P11_KIT_BUILDLINK3_MK)
P11_KIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.10
BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23
BUILDLINK_ABI_DEPENDS.p11-kit?=	p11-kit>=0.23.15nb1
BUILDLINK_PKGSRCDIR.p11-kit?=	../../security/p11-kit
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.endif	# P11_KIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p11-kit
