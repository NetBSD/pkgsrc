# $NetBSD: buildlink3.mk,v 1.1 2018/02/26 02:25:28 khorben Exp $

BUILDLINK_TREE+=	unicorn

.if !defined(UNICORN_BUILDLINK3_MK)
UNICORN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unicorn+=	unicorn>=1.0.1
BUILDLINK_PKGSRCDIR.unicorn?=		../../emulators/unicorn
.endif	# UNICORN_BUILDLINK3_MK

BUILDLINK_TREE+=	-unicorn
