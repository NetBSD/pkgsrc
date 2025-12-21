# $NetBSD: buildlink3.mk,v 1.4 2025/12/21 15:14:45 markd Exp $

BUILDLINK_TREE+=	okular

.if !defined(OKULAR_BUILDLINK3_MK)
OKULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.okular+=	okular>=25.08.2
BUILDLINK_PKGSRCDIR.okular?=	../../print/okular

.endif	# OKULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-okular
