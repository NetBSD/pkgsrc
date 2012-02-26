# $NetBSD: buildlink3.mk,v 1.1 2012/02/26 14:02:31 jmmv Exp $

BUILDLINK_TREE+=	lutok

.if !defined(LUTOK_BUILDLINK3_MK)
LUTOK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lutok+=	lutok>=0.1
BUILDLINK_PKGSRCDIR.lutok?=	../../devel/lutok

.include "../../lang/lua/buildlink3.mk"
.endif	# LUTOK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lutok
