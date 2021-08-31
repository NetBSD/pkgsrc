# $NetBSD: buildlink3.mk,v 1.3 2021/08/31 11:29:24 markd Exp $

BUILDLINK_TREE+=	okular

.if !defined(OKULAR_BUILDLINK3_MK)
OKULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.okular+=	okular>=20.12.3nb8
BUILDLINK_PKGSRCDIR.okular?=	../../print/okular

.endif	# OKULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-okular
