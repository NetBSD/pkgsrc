# $NetBSD: buildlink3.mk,v 1.1 2020/12/10 16:25:19 kardel Exp $

BUILDLINK_TREE+=	libyang

.if !defined(LIBYANG_BUILDLINK3_MK)
LIBYANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyang+=	libyang>=1.0.184
BUILDLINK_PKGSRCDIR.libyang?=	../../devel/libyang
TOOL_DEPENDS+=			cmocka>=1.1.5:../../devel/cmocka

.include "../../devel/pcre/buildlink3.mk"

.endif	# LIBYANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyang
