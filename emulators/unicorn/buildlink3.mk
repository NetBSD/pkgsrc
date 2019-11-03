# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 19:24:34 rillig Exp $

BUILDLINK_TREE+=	unicorn

.if !defined(UNICORN_BUILDLINK3_MK)
UNICORN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unicorn+=	unicorn>=1.0.1
BUILDLINK_PKGSRCDIR.unicorn?=	../../emulators/unicorn
.endif	# UNICORN_BUILDLINK3_MK

BUILDLINK_TREE+=	-unicorn
