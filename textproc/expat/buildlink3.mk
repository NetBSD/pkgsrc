# $NetBSD: buildlink3.mk,v 1.19 2009/03/20 19:25:28 joerg Exp $

BUILDLINK_TREE+=	expat

.if !defined(EXPAT_BUILDLINK3_MK)
EXPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.expat+=	expat>=1.95.7
BUILDLINK_ABI_DEPENDS.expat+=	expat>=2.0.0nb1
BUILDLINK_PKGSRCDIR.expat?=	../../textproc/expat
.endif # EXPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-expat
