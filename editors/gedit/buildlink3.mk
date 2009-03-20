# $NetBSD: buildlink3.mk,v 1.16 2009/03/20 19:24:31 joerg Exp $

BUILDLINK_TREE+=	gedit

.if !defined(GEDIT_BUILDLINK3_MK)
GEDIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gedit+=	gedit>=2.12.1nb4
BUILDLINK_ABI_DEPENDS.gedit?=	gedit>=2.20.4nb2
BUILDLINK_PKGSRCDIR.gedit?=	../../editors/gedit

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.endif # GEDIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gedit
