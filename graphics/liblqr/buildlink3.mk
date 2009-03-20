# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:42 joerg Exp $

BUILDLINK_TREE+=	liblqr

.if !defined(LIBLQR_BUILDLINK3_MK)
LIBLQR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblqr+=	liblqr>=0.1.0.2
BUILDLINK_PKGSRCDIR.liblqr?=	../../graphics/liblqr

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBLQR_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblqr
