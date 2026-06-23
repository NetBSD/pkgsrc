# $NetBSD: buildlink3.mk,v 1.5 2026/06/23 09:52:56 wiz Exp $

BUILDLINK_TREE+=	argp

.if !defined(ARGP_BUILDLINK3_MK)
ARGP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.argp?=	build

BUILDLINK_API_DEPENDS.argp+=	argp>=1.5.0
BUILDLINK_ABI_DEPENDS.argp?=	argp>=1.5.0
BUILDLINK_PKGSRCDIR.argp?=	../../devel/argp
.endif	# ARGP_BUILDLINK3_MK

BUILDLINK_TREE+=	-argp
