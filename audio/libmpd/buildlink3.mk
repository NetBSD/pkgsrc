# $NetBSD: buildlink3.mk,v 1.8 2009/05/30 00:44:59 obache Exp $

BUILDLINK_TREE+=	libmpd

.if !defined(LIBMPD_BUILDLINK3_MK)
LIBMPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpd+=	libmpd>=0.12.0
BUILDLINK_ABI_DEPENDS.libmpd+=	libmpd>=0.18.0
BUILDLINK_PKGSRCDIR.libmpd?=	../../audio/libmpd
.endif # LIBMPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpd
