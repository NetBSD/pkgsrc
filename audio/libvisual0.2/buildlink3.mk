# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:23:57 joerg Exp $

BUILDLINK_TREE+=	libvisual0.2

.if !defined(LIBVISUAL0.2_BUILDLINK3_MK)
LIBVISUAL0.2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvisual0.2+=	libvisual0.2>=0.2.0
BUILDLINK_PKGSRCDIR.libvisual0.2?=	../../audio/libvisual0.2
.endif # LIBVISUAL0.2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvisual0.2
