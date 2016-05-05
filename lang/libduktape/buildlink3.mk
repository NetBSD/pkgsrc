# $NetBSD: buildlink3.mk,v 1.1 2016/05/05 03:57:26 agc Exp $

BUILDLINK_TREE+=	libduktape

.if !defined(LIBDUKTAPE_BUILDLINK3_MK)
LIBDUKTAPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libduktape+=	libduktape>=1.5.0
BUILDLINK_PKGSRCDIR.libduktape?=	../../lang/libduktape
.endif	# LIBDUKTAPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libduktape
