# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:24 joerg Exp $

BUILDLINK_TREE+=	mono-tools

.if !defined(MONO_TOOLS_BUILDLINK3_MK)
MONO_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-tools+=	mono-tools>=2.0
BUILDLINK_PKGSRCDIR.mono-tools?=	../../devel/mono-tools
.endif # MONO_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-tools
