# $NetBSD: buildlink3.mk,v 1.6 2026/06/26 06:15:09 wiz Exp $

BUILDLINK_TREE+=	argp

.if !defined(ARGP_BUILDLINK3_MK)
ARGP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.argp+=	argp>=1.5.0nb1
BUILDLINK_ABI_DEPENDS.argp?=	argp>=1.5.0nb1
BUILDLINK_PKGSRCDIR.argp?=	../../devel/argp
.endif	# ARGP_BUILDLINK3_MK

BUILDLINK_TREE+=	-argp
