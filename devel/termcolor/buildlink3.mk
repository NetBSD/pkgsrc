# $NetBSD: buildlink3.mk,v 1.1 2021/12/31 17:25:25 plunky Exp $

BUILDLINK_TREE+=	termcolor

.if !defined(TERMCOLOR_BUILDLINK3_MK)
TERMCOLOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.termcolor+=	termcolor>=2.0.0
BUILDLINK_PKGSRCDIR.termcolor?=		../../devel/termcolor
.endif

BUILDLINK_TREE+=	-termcolor
