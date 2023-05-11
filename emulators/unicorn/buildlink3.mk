# $NetBSD: buildlink3.mk,v 1.3 2023/05/11 06:47:11 adam Exp $

BUILDLINK_TREE+=	unicorn

.if !defined(UNICORN_BUILDLINK3_MK)
UNICORN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unicorn+=	unicorn>=2.0.0
BUILDLINK_PKGSRCDIR.unicorn?=	../../emulators/unicorn
.endif	# UNICORN_BUILDLINK3_MK

BUILDLINK_TREE+=	-unicorn
