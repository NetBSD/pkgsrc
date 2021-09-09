# $NetBSD: buildlink3.mk,v 1.2 2021/09/09 07:39:15 kardel Exp $

BUILDLINK_TREE+=	libyang

.if !defined(LIBYANG_BUILDLINK3_MK)
LIBYANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyang+=	libyang>=1.0.240
BUILDLINK_PKGSRCDIR.libyang?=	../../devel/libyang
TOOL_DEPENDS+=			cmocka>=1.1.5:../../devel/cmocka

.include "../../devel/pcre/buildlink3.mk"

.endif	# LIBYANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyang
