# $NetBSD: buildlink3.mk,v 1.25 2018/07/20 03:33:50 ryoon Exp $

BUILDLINK_TREE+=	mono-addins

.if !defined(MONO_ADDINS_BUILDLINK3_MK)
MONO_ADDINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-addins+=	mono-addins>=0.3
BUILDLINK_ABI_DEPENDS.mono-addins+=	mono-addins>=1.1nb8
BUILDLINK_PKGSRCDIR.mono-addins?=	../../devel/mono-addins
BUILDLINK_CONTENTS_FILTER.mono-addins+=	${EGREP} '^lib/'

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.endif # MONO_ADDINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-addins
