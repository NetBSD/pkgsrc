# $NetBSD: buildlink3.mk,v 1.6 2012/03/03 00:11:58 wiz Exp $

BUILDLINK_TREE+=	liblqr

.if !defined(LIBLQR_BUILDLINK3_MK)
LIBLQR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblqr+=	liblqr>=0.4.1
BUILDLINK_ABI_DEPENDS.liblqr?=	liblqr>=0.4.1nb3
BUILDLINK_PKGSRCDIR.liblqr?=	../../graphics/liblqr

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBLQR_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblqr
