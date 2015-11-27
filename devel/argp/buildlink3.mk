# $NetBSD: buildlink3.mk,v 1.3 2015/11/27 17:43:38 joerg Exp $

BUILDLINK_TREE+=	argp

.if !defined(ARGP_BUILDLINK3_MK)
ARGP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.argp+=	argp>=1.3
BUILDLINK_PKGSRCDIR.argp?=	../../devel/argp
.endif # ARGP_BUILDLINK3_MK

BUILDLINK_TREE+=	-argp
