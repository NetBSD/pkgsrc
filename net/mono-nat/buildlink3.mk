# $NetBSD: buildlink3.mk,v 1.32 2024/11/01 00:53:11 wiz Exp $

BUILDLINK_TREE+=	mono-nat

.if !defined(MONO_NAT_BUILDLINK3_MK)
MONO_NAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-nat+=	mono-nat>=1.0.2
BUILDLINK_ABI_DEPENDS.mono-nat+=	mono-nat>=1.0.2nb33
BUILDLINK_PKGSRCDIR.mono-nat?=		../../net/mono-nat

.include "../../lang/mono/buildlink3.mk"

.endif	# MONO_NAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-nat
