# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libmpd

.if !defined(LIBMPD_BUILDLINK3_MK)
LIBMPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpd+=	libmpd>=0.12.0
BUILDLINK_PKGSRCDIR.libmpd?=	../../audio/libmpd
.endif # LIBMPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpd
