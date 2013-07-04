# $NetBSD: buildlink3.mk,v 1.3 2013/07/04 21:27:58 adam Exp $

BUILDLINK_TREE+=	libquvi

.if !defined(LIBQUVI_BUILDLINK3_MK)
LIBQUVI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libquvi+=	libquvi>=0.4.0
BUILDLINK_ABI_DEPENDS.libquvi?=	libquvi>=0.4.1nb3
BUILDLINK_PKGSRCDIR.libquvi?=	../../net/libquvi

.include "../../lang/lua/buildlink3.mk"
.include "../../net/libquvi-scripts/buildlink3.mk"
.endif	# LIBQUVI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libquvi
