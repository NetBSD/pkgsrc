# $NetBSD: buildlink3.mk,v 1.2 2023/11/23 11:12:33 jperkin Exp $

BUILDLINK_TREE+=	gettext-tools

.if !defined(GETTEXT_TOOLS_BUILDLINK3_MK)
GETTEXT_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gettext-tools+=	gettext-tools>=0.18.1.1nb3
BUILDLINK_PKGSRCDIR.gettext-tools?=	../../devel/gettext-tools

.include "../../mk/termcap.buildlink3.mk"
.endif	# GETTEXT_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext-tools
