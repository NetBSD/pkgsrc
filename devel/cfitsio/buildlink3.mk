# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:11 joerg Exp $

BUILDLINK_TREE+=	cfitsio

.if !defined(CFITSIO_BUILDLINK3_MK)
CFITSIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cfitsio+=	cfitsio>=3.100
BUILDLINK_PKGSRCDIR.cfitsio?=	../../devel/cfitsio
.endif # CFITSIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cfitsio
