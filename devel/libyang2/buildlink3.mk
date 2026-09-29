# $NetBSD: buildlink3.mk,v 1.7 2026/09/29 06:04:36 wiz Exp $

BUILDLINK_TREE+=	libyang2

.if !defined(LIBYANG2_BUILDLINK3_MK)
LIBYANG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyang2+=	libyang2>=2.1.128
BUILDLINK_ABI_DEPENDS.libyang2?=		libyang2>=2.1.128nb5
BUILDLINK_PKGSRCDIR.libyang2?=		../../devel/libyang2

TOOL_DEPENDS+=			cmocka>=1.1.5:../../devel/cmocka

.include "../../devel/pcre2/buildlink3.mk"

.endif	# LIBYANG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyang2
