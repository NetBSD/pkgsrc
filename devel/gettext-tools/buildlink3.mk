# $NetBSD: buildlink3.mk,v 1.1 2012/12/03 13:07:20 ryoon Exp $

BUILDLINK_TREE+=	gettext-tools

.if !defined(GETTEXT_TOOLS_BUILDLINK3_MK)
GETTEXT_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gettext-tools+=	gettext-tools>=0.18.1.1nb3
BUILDLINK_PKGSRCDIR.gettext-tools?=	../../devel/gettext-tools

.endif	# GETTEXT_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext-tools
