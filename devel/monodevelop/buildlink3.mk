# $NetBSD: buildlink3.mk,v 1.61 2020/03/08 16:47:39 wiz Exp $

BUILDLINK_TREE+=	monodevelop

.if !defined(MONODEVELOP_BUILDLINK3_MK)
MONODEVELOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monodevelop+=	monodevelop>=5.0
BUILDLINK_ABI_DEPENDS.monodevelop+=	monodevelop>=5.0.1nb28
BUILDLINK_PKGSRCDIR.monodevelop?=	../../devel/monodevelop
BUILDLINK_CONTENTS_FILTER.monodevelop=	${EGREP} '^lib/'

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtksourceview-sharp2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.endif	# MONODEVELOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-monodevelop
