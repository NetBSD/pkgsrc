# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:16 joerg Exp $

BUILDLINK_TREE+=	libbegemot

.if !defined(LIBBEGEMOT_BUILDLINK3_MK)
LIBBEGEMOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbegemot+=	libbegemot>=1.9nb1
BUILDLINK_PKGSRCDIR.libbegemot?=	../../devel/libbegemot
.endif # LIBBEGEMOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbegemot
