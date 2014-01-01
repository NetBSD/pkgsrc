# $NetBSD: buildlink3.mk,v 1.10 2014/01/01 11:52:06 wiz Exp $

BUILDLINK_TREE+=	liblrdf

.if !defined(LIBLRDF_BUILDLINK3_MK)
LIBLRDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblrdf+=	liblrdf>=0.4.0nb1
BUILDLINK_ABI_DEPENDS.liblrdf+=	liblrdf>=0.5.0nb4
BUILDLINK_PKGSRCDIR.liblrdf?=	../../textproc/liblrdf

.include "../../textproc/raptor2/buildlink3.mk"
.endif # LIBLRDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblrdf
