# $NetBSD: buildlink3.mk,v 1.2 2021/08/11 09:53:36 kardel Exp $

BUILDLINK_TREE+=	libyang2

.if !defined(LIBYANG2_BUILDLINK3_MK)
LIBYANG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyang2+=	libyang2>=2.0.7
BUILDLINK_PKGSRCDIR.libyang2?=		../../devel/libyang2

TOOL_DEPENDS+=			cmocka>=1.1.5:../../devel/cmocka

.include "../../devel/pcre2/buildlink3.mk"

.endif	# LIBYANG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyang2
