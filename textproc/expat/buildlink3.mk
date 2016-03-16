# $NetBSD: buildlink3.mk,v 1.20 2016/03/16 19:55:55 ryoon Exp $

BUILDLINK_TREE+=	expat

.if !defined(EXPAT_BUILDLINK3_MK)
EXPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.expat+=	expat>=2.1.1
BUILDLINK_ABI_DEPENDS.expat+=	expat>=2.1.1
BUILDLINK_PKGSRCDIR.expat?=	../../textproc/expat
.endif # EXPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-expat
