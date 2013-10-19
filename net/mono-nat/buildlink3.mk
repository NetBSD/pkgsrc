# $NetBSD: buildlink3.mk,v 1.9 2013/10/19 09:06:58 adam Exp $

BUILDLINK_TREE+=	mono-nat

.if !defined(MONO_NAT_BUILDLINK3_MK)
MONO_NAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-nat+=	mono-nat>=1.0.2
BUILDLINK_ABI_DEPENDS.mono-nat+=	mono-nat>=1.0.2nb8
BUILDLINK_PKGSRCDIR.mono-nat?=	../../net/mono-nat

.include "../../lang/mono2/buildlink3.mk"

.endif	# MONO_NAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-nat
