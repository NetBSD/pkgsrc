# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/20 00:34:54 markd Exp $

BUILDLINK_TREE+=	okular

.if !defined(OKULAR_BUILDLINK3_MK)
OKULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.okular+=	okular>=4.8.0
BUILDLINK_PKGSRCDIR.okular?=	../../print/okular

.endif	# OKULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-okular
