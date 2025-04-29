# $NetBSD: buildlink3.mk,v 1.1 2025/04/29 07:57:35 nia Exp $

BUILDLINK_TREE+=	pkgconf

.if !defined(PKGCONF_BUILDLINK3_MK)
PKGCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pkgconf+=		pkgconf>=1.9.4<2.4.0
BUILDLINK_PKGSRCDIR.pkgconf?=		../../devel/pkgconf23
.endif	# PKGCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-pkgconf
