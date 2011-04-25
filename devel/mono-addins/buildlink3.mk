# $NetBSD: buildlink3.mk,v 1.7 2011/04/25 14:02:30 kefren Exp $

BUILDLINK_TREE+=	mono-addins

.if !defined(MONO_ADDINS_BUILDLINK3_MK)
MONO_ADDINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-addins+=	mono-addins>=0.3
BUILDLINK_ABI_DEPENDS.mono-addins?=	mono-addins>=0.5nb1
BUILDLINK_PKGSRCDIR.mono-addins?=	../../devel/mono-addins
BUILDLINK_CONTENTS_FILTER.mono-addins+=	${EGREP} '^lib/'

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.endif # MONO_ADDINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-addins
