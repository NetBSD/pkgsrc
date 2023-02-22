# $NetBSD: buildlink3.mk,v 1.1 2023/02/22 15:51:41 micha Exp $

BUILDLINK_TREE+=	pkgconf

.if !defined(PKGCONF_BUILDLINK3_MK)
PKGCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pkgconf+=		pkgconf>=1.9.4
BUILDLINK_PKGSRCDIR.pkgconf?=		../../devel/pkgconf
.endif	# PKGCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-pkgconf
