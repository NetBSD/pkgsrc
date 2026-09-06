# $NetBSD: buildlink3.mk,v 1.1 2026/09/06 09:21:58 markd Exp $

BUILDLINK_TREE+=	corrosion

.if !defined(CORROSION_BUILDLINK3_MK)
CORROSION_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.corrosion?=	build

BUILDLINK_API_DEPENDS.corrosion+=	corrosion>=0.6.1
BUILDLINK_PKGSRCDIR.corrosion?=		../../devel/corrosion
.endif	# CORROSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-corrosion
