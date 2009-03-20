# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:04 joerg Exp $
#

BUILDLINK_TREE+=	libogg

.if !defined(LIBOGG_BUILDLINK3_MK)
LIBOGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1
BUILDLINK_ABI_DEPENDS.libogg+=	libogg>=1.1.2nb1
BUILDLINK_PKGSRCDIR.libogg?=	../../multimedia/libogg
.endif # LIBOGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libogg
