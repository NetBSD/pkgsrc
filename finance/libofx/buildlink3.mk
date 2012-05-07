# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:29 dholland Exp $

BUILDLINK_TREE+=	libofx

.if !defined(LIBOFX_BUILDLINK3_MK)
LIBOFX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libofx+=	libofx>=0.8.0
BUILDLINK_ABI_DEPENDS.libofx+=	libofx>=0.9.1nb1
BUILDLINK_PKGSRCDIR.libofx?=	../../finance/libofx
BUILDLINK_INCDIRS.libofx+=	include/libofx

.include "../../textproc/opensp/buildlink3.mk"
.endif # LIBOFX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libofx
