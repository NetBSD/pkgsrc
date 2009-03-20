# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:13 joerg Exp $

BUILDLINK_TREE+=	a2ps

.if !defined(A2PS_BUILDLINK3_MK)
A2PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.a2ps+=	a2ps>=4.13.0.2nb4
BUILDLINK_ABI_DEPENDS.a2ps?=	a2ps>=4.13.0.2nb10
BUILDLINK_PKGSRCDIR.a2ps?=	../../print/a2ps

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # A2PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-a2ps
