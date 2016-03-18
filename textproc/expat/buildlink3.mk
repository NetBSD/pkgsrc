# $NetBSD: buildlink3.mk,v 1.21 2016/03/18 09:36:26 wiz Exp $

BUILDLINK_TREE+=	expat

.if !defined(EXPAT_BUILDLINK3_MK)
EXPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.expat+=	expat>=1.95.7
BUILDLINK_ABI_DEPENDS.expat+=	expat>=2.0.0nb1
BUILDLINK_PKGSRCDIR.expat?=	../../textproc/expat
.endif # EXPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-expat
