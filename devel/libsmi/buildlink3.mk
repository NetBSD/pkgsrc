# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libsmi

.if !defined(LIBSMI_BUILDLINK3_MK)
LIBSMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsmi+=	libsmi>=0.4.5nb1
BUILDLINK_PKGSRCDIR.libsmi?=	../../devel/libsmi
.endif # LIBSMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsmi
