# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/14 21:43:52 minskim Exp $
#
# This Makefile fragment is included by packages that use gnome-spell.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_SPELL_BUILDLINK3_MK:=	${GNOME_SPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-spell
.endif

.if !empty(GNOME_SPELL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-spell
BUILDLINK_DEPENDS.gnome-spell+=		gnome-spell>=1.0.5
BUILDLINK_PKGSRCDIR.gnome-spell?=		../../wip/gnome-spell

.include "../../net/ORBit2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # GNOME_SPELL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
