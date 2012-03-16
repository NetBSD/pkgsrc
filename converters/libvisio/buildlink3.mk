# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/16 17:40:37 wiz Exp $

BUILDLINK_TREE+=	libvisio

.if !defined(LIBVISIO_BUILDLINK3_MK)
LIBVISIO_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.libvisio+=	libvisio>=0.0.15
BUILDLINK_PKGSRCDIR.libvisio?=		../../converters/libvisio
.endif

BUILDLINK_TREE+=	-libvisio
