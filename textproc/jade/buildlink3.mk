# $NetBSD: buildlink3.mk,v 1.9 2011/04/22 13:42:00 obache Exp $

BUILDLINK_TREE+=	jade

.if !defined(JADE_BUILDLINK3_MK)
JADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jade+=	jade>=1.2.1nb7
BUILDLINK_ABI_DEPENDS.jade+=	jade>=1.2.1nb13
BUILDLINK_PKGSRCDIR.jade?=	../../textproc/jade

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # JADE_BUILDLINK3_MK

BUILDLINK_TREE+=	-jade
