# $NetBSD: buildlink3.mk,v 1.3 2013/07/04 21:27:57 adam Exp $

BUILDLINK_TREE+=	lutok

.if !defined(LUTOK_BUILDLINK3_MK)
LUTOK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lutok+=	lutok>=0.3
BUILDLINK_ABI_DEPENDS.lutok?=	lutok>=0.3nb1
BUILDLINK_PKGSRCDIR.lutok?=	../../devel/lutok

.include "../../lang/lua/buildlink3.mk"
.endif	# LUTOK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lutok
