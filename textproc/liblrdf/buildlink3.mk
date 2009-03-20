# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:30 joerg Exp $

BUILDLINK_TREE+=	liblrdf

.if !defined(LIBLRDF_BUILDLINK3_MK)
LIBLRDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblrdf+=	liblrdf>=0.4.0nb1
BUILDLINK_PKGSRCDIR.liblrdf?=	../../textproc/liblrdf

.include "../../textproc/raptor/buildlink3.mk"
.endif # LIBLRDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblrdf
