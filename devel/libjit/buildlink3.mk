# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libjit

.if !defined(LIBJIT_BUILDLINK3_MK)
LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjit+=	libjit>=0.0.2
BUILDLINK_ABI_DEPENDS.libjit+=	libjit>=0.0.4nb1
BUILDLINK_PKGSRCDIR.libjit?=	../../devel/libjit
.endif # LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjit
