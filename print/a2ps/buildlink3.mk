# $NetBSD: buildlink3.mk,v 1.10 2022/06/28 11:35:27 wiz Exp $

BUILDLINK_TREE+=	a2ps

.if !defined(A2PS_BUILDLINK3_MK)
A2PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.a2ps+=	a2ps>=4.13.0.2nb4
BUILDLINK_ABI_DEPENDS.a2ps+=	a2ps>=4.14nb15
BUILDLINK_PKGSRCDIR.a2ps?=	../../print/a2ps

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # A2PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-a2ps
